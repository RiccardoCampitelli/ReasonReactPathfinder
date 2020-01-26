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
  let setNodeStatusToChecked = (_event, colIndex, rowIndex) => {
    setNodeStatus(
      ~col=colIndex,
      ~row=rowIndex,
      ~newStatus=PathFinderTypes.Checked(true),
      (),
    );
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
                     key={colIndex->string_of_int ++ rowIndex -> string_of_int}
                     status
                     onClick={__x =>
                       setNodeStatusToChecked(__x, colIndex, rowIndex)
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
