type status = 
    | Checked(bool)
    | Wall(bool)
    | Path(bool)
    | Empty(bool)
    | StartNode(bool)
    | EndNode(bool);