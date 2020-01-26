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

let updateNode = (board, (x,y), newStatus) => {

   let newBoard =
        Array.mapi(
          (rowIndex, rowArray) => {
            let newRow =
              rowIndex === y
                ? Array.mapi(
                    (colIndex, node) => {
                      let res = colIndex === x ? newStatus : node;

                      res;
                    },
                    rowArray,
                  )
                : Array.copy(rowArray);

            newRow;
          },
          board,
        );

newBoard;
};

[@react.component]
let make = () => {
  let (board, setBoard) = React.useState(() => createEmptyBoard());

  let setNodeStatus = (~col: int, ~row: int, ~newStatus: PathFinderTypes.status, ()) => {
    setBoard(oldBoard => {
      let newBoard = updateNode(oldBoard, (col,row), newStatus);
      newBoard;
    });
  };

  <div className=Styles.appContainer> <Board board setNodeStatus/> </div>;
};
