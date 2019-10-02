open Troll;
let formater: list(Troll.t) => string =
  warband =>
    List.map(
      troll =>
        "Troll "
        ++ troll.name
        ++ " scored "
        ++ string_of_int(Troll.scoring(troll))
        ++ "\n",
      warband,
    )
    |> List.fold_left((++), "");
let logger: string => unit =
  warband => {
    Console.log(
      <Pastel>
        <Pastel color=Red> "Troll of Fame\n" </Pastel>
        <Pastel color=Green> warband </Pastel>
      </Pastel>,
    );
  };

let print_warband = warband => formater(warband) |> logger;