open PathFinderTypes;

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
  let (clickedNode, setClickedNode) = React.useState(() => Empty(true));

  let handleMouseDown = (_event, colIndex, rowIndex, currentStatus: status) => {
    setClickedNode(_ => currentStatus);

    switch (currentStatus) {
    | Wall(true) => setNodeStatus(colIndex, rowIndex, Empty(true))
    | Empty(true) => setNodeStatus(colIndex, rowIndex, Wall(true))
    | _ => setNodeStatus(colIndex, rowIndex, currentStatus)
    };
  };

  let handleMouseEnter = (event, colIndex, rowIndex, currentStatus: status) => {
    ReactEvent.Mouse.persist(event);

    let buttons = event->ReactEvent.Mouse.buttons;
    let isMousePressed = buttons === 1;

    let wasStartOrEndNodeClicked =
      clickedNode == StartNode(true) || clickedNode == EndNode(true);

    switch (currentStatus, isMousePressed, wasStartOrEndNodeClicked) {
    | (_, true, true) => setNodeStatus(colIndex, rowIndex, clickedNode)
    | (Wall(true), true, _) =>
      setNodeStatus(colIndex, rowIndex, Empty(true))
    | (Empty(true), true, _) =>
      setNodeStatus(colIndex, rowIndex, Wall(true))
    | (_, false, _) => setNodeStatus(colIndex, rowIndex, currentStatus)
    | (_, _, _) => ()
    };
  };

  let handleMouseLeave = (event, colIndex, rowIndex) => {
    ReactEvent.Mouse.persist(event);
    // Js.log(event->ReactEvent.Mouse.buttons);
    let buttons = event->ReactEvent.Mouse.buttons;
    let isMousePressed = buttons === 1;

    let wasStartOrEndNodeClicked =
      clickedNode == StartNode(true) || clickedNode == EndNode(true);

    if (isMousePressed && wasStartOrEndNodeClicked) {
      setNodeStatus(colIndex, rowIndex, Empty(true));
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
                     key={
                       colIndex->string_of_int
                       ++ "-"
                       ++ rowIndex->string_of_int
                     }
                     status
                     onMouseDown={__x =>
                       handleMouseDown(__x, colIndex, rowIndex, status)
                     }
                     onMouseEnter={event =>
                       handleMouseEnter(event, colIndex, rowIndex, status)
                     }
                     onMouseLeave={event =>
                       handleMouseLeave(event, colIndex, rowIndex)
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
