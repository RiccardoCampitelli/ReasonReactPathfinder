module Styles = {
  open Css;

  let node = (status: PathFinderTypes.status) =>
    style([
      height(`px(15)),
      width(`px(15)),
      outline(`px(1), `solid, black),
      backgroundColor(switch status {
      | Wall(true)  => blue
      | Checked(true) => darkblue
      | _ => papayawhip
      }),
      cursor(`pointer)
    ]);
};



[@react.component]
let make = (~status, ~onClick) => {


  <div className={Styles.node(status)} onClick />;
};
