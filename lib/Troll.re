
module Killed = Map.Make(Elf);

type score = int;
type kill = int;

type t = {
  name: string,
  kills: Killed.t(kill),
};

let scoring: t => score =
  troll => {
    Killed.fold((k, v, accum) => Elf.value(k) * v + accum, troll.kills, 0);
  };

let modify_score: (option(kill) => option(kill), Elf.t, t) => t =
  (modifier, elf, troll) => {
    let how_much = Killed.find_opt(elf, troll.kills);
    let new_kills =
      switch (modifier(how_much)) {
      | Some(0) => Killed.remove(elf, troll.kills)
      | Some(hits) => Killed.update(elf, modifier, troll.kills)
      | None => troll.kills /* Oops nothing to do */
      };
    {...troll, kills: new_kills};
  };

let optional_add: (option(kill), option(kill)) => option(kill) =
  (a, b) => {
    switch (a, b) {
    | (Some(x), Some(y)) => Some(x + y)
    | _ => None
    };
  };

let i_got: (kill, Elf.t, t) => t =
  (num, elf, troll) => {
    modify_score(optional_add(Some(num)), elf, troll);
  };

let i_got_one = i_got(1);

let oops_he_survived = i_got(-1);

let all_elves_of_a_kind_resurrected: (Elf.t, t) => t =
  (elf, troll) => {
    let without_resurected = Killed.remove(elf, troll.kills);
    {...troll, kills: without_resurected};
  };