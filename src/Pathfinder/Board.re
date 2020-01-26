module Styles = {
  open Css;

  let gridContainer = style([display(`flex), justifyContent(`center)]);

  let grid =
    style([
      display(`flex),
      flexWrap(`wrap),
      width(`px(600)),
      height(`px(160)),
    ]);
};

[@react.component]
let make = (~board, ~setNodeStatus) => {
  let toggleNodeStatus =
      (_event, colIndex, rowIndex, currentStatus: PathFinderTypes.status) => {
    switch (currentStatus) {
    | Wall(true) =>
      setNodeStatus(colIndex, rowIndex, PathFinderTypes.Empty(true))
    | Empty(true) =>
      setNodeStatus(colIndex, rowIndex, PathFinderTypes.Wall(true))
    | _ => setNodeStatus(colIndex, rowIndex, currentStatus)
    };
  };

  let handleMouseEnter =
      (event, colIndex, rowIndex, currentStatus: PathFinderTypes.status) => {
    ReactEvent.Mouse.persist(event);
    Js.log(event->ReactEvent.Mouse.buttons);
    let buttons = event->ReactEvent.Mouse.buttons;
    let isMousePressed = buttons === 1 || buttons === 2;
    //TODO: Check ReactEvent.Mouse.buttons and get rid of isMouseDown state

    switch (currentStatus, isMousePressed) {
    | (Wall(true), true) =>
      setNodeStatus(colIndex, rowIndex, PathFinderTypes.Empty(true))
    | (Empty(true), true) =>
      setNodeStatus(colIndex, rowIndex, PathFinderTypes.Wall(true))
    | (_, false) => setNodeStatus(colIndex, rowIndex, currentStatus)
    | (_, _) => ()
    };
  };

  <div className=Styles.gridContainer>
    <div className=Styles.grid>
      {board
       ->Array.mapi(
           (rowIndex, row) => {
             row
             ->Array.mapi(
                 (colIndex, status) => {
                   <Node
                     key={colIndex->string_of_int ++ rowIndex->string_of_int}
                     status
                     onClick={__x =>
                       toggleNodeStatus(__x, colIndex, rowIndex, status)
                     }
                     onMouseEnter={event =>
                       handleMouseEnter(event, colIndex, rowIndex, status)
                     }
                   />
                 },
                 _,
               )
             ->React.array
           },
           _,
         )
       ->React.array}
    </div>
  </div>;
};
