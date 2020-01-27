module Styles = {
  open Css;

  let node = (status: PathFinderTypes.status) =>
    style([
      height(`px(15)),
      width(`px(15)),
      outline(`px(1), `solid, black),
      backgroundColor(
        switch (status) {
        | Wall(true) => blue
        | Checked(true) => darkblue
        | Path(true) => lightyellow
        | StartNode(true) => lightgreen
        | EndNode(true) => purple
        | _ => papayawhip
        },
      ),
      cursor(`pointer),
    ]);
};

let preventDragHandler = (_event) => {
  ReactEvent.Mouse.preventDefault(_event)
};

[@react.component]
let make = (~status, ~onClick, ~onMouseEnter) => {
  <div
    className={Styles.node(status)}
    onClick
    onMouseEnter
    onDragStart={preventDragHandler}
  />;
};
