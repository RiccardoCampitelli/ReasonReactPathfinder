module Styles = {
  open Css;

  let appContainer =
    style([
      position(`absolute),
      height(`vh(100->float_of_int)),
      width(`percent(100->float_of_int)),
    ]);
};

let defaultBoardHeight = 20;
let defaultBoardWidth = 20;

let createEmptyBoard = () => {
  Array.make_matrix(
    defaultBoardHeight,
    defaultBoardWidth,
    PathFinderTypes.Empty(true),
  );
};

[@react.component]
let make = () => {
  let (board, setBoard) = React.useState(() => createEmptyBoard());

  let setNodeStatus = (~col: int, ~row: int, ~newStatus: PathFinderTypes.status, ()) => {
    setBoard(oldBoard => {
      let newBoard =
        Array.mapi(
          (rowIndex, rowArray) => {
            let newRow =
              rowIndex === row
                ? Array.mapi(
                    (colIndex, node) => {
                      let res = colIndex === col ? newStatus : node;

                      res;
                    },
                    rowArray,
                  )
                : Array.copy(rowArray);

            newRow;
          },
          oldBoard,
        );
      newBoard;
    });
  };

  <div className=Styles.appContainer> <Board board setNodeStatus/> </div>;
};
