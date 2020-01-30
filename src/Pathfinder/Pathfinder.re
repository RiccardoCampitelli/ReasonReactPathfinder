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

let rec findInArray = (arr, i, pred) =>
  if (i >= Array.length(arr)) {
    None;
  } else if (pred(arr[i])) {
    Some(i);
  } else {
    findInArray(arr, i + 1, pred);
  };

let getStartNodeCoords = (board: array(array(status))) => {
  let colIndex = ref(0);

  let rowIndex =
  findInArray(
    board,
    0,
    col => {
      let isInCol =
        findInArray(col, 0, node => {
          node == StartNode(true) ? true : false
        });

      switch (isInCol) {
      | None => false
      | Some(value) =>
        colIndex := value;
        true;
      };
    },
  );

  (rowIndex, colIndex^)
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

  let findStartNode = _ => {
    Js.log(getStartNodeCoords(board));
  };

  <div className=Styles.appContainer>
    <div>
      <button onClick=resetBoard> "Reset board"->React.string </button>
      <button onClick=findStartNode> "Test"->React.string </button>
    </div>
    <Board board setNodeStatus />
  </div>;
};
