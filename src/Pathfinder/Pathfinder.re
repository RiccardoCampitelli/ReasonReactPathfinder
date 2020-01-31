open PathFinderTypes;
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
  let initialBoard =
    Array.make_matrix(defaultBoardHeight, defaultBoardWidth, Empty(true));

  initialBoard[8][4] = StartNode(true);
  initialBoard[9][14] = EndNode(true);

  initialBoard;
};

let updateNode = (board, (x, y), newStatus) => {
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

// let rec findInArray = (arr, i, pred) =>
//   if (i >= Array.length(arr)) {
//     None;
//   } else if (pred(arr[i])) {
//     Some(i);
//   } else {
//     findInArray(arr, i + 1, pred);
//   };

let rec findInMatrix = (matrix, i, j, pred) =>
  if (i >= Array.length(matrix) && j >= Array.length(matrix)) {
    None;
  } else if (pred(matrix[i][j])) {
    Some((i, j));
  } else {
    let colIndexInRange = i < Array.length(matrix) - 1;
    let rowIndexInRange = j < Array.length(matrix) - 1;

    switch (colIndexInRange, rowIndexInRange) {
    | (true, true) => findInMatrix(matrix, i + 1, j, pred)
    | (false, true) => findInMatrix(matrix, 0, j + 1, pred)
    | (_, _) => None
    };
  };

let getStartNodeCoords = (board: array(array(status))) => {
  findInMatrix(board, 0, 0, value => value == StartNode(true));
};

let getEndNodeCoords = (board: array(array(status))) => {
  findInMatrix(board, 0, 0, value => value == EndNode(true));
};

[@react.component]
let make = () => {
  let (board, setBoard) = React.useState(() => createEmptyBoard());

  let setNodeStatus = (col: int, row: int, newStatus: status) => {
    setBoard(oldBoard => {
      let newBoard = updateNode(oldBoard, (col, row), newStatus);
      newBoard;
    });
  };

  let resetBoard = _event => {
    setBoard(_ => createEmptyBoard());
  };

  let test = _ => {
    let startNode = getStartNodeCoords(board);
    let endNode = getEndNodeCoords(board);

    Js.log((startNode, endNode))

  };

  <div className=Styles.appContainer>
    <div>
      <button onClick=resetBoard> "Reset board"->React.string </button>
      <button onClick=test> "Test"->React.string </button>
    </div>
    <Board board setNodeStatus />
  </div>;
};
