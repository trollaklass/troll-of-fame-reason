module Killed = Map.Make(Elf);

type score = int;
type kill = int;

type t = {
  name: string,
  kills: Killed.t(kill),
};
let scoring: t => score =
  troll => {
    Killed.fold((k, v, accum) => Elf.value(k) * v, troll.kills, 0);
  };

let modify_score: (option(kill) => option(kill), Elf.t, t) => t =
  (modifier, elf, troll) => {
    {name: troll.name, kills: Killed.update(elf, modifier, troll.kills)};
  };

let optional_add: (option(kill), option(kill)) => option(kill) =
  (a, b) => {
    switch (a, b) {
    | (Some(x), None) => a
    | (Some(x), Some(y)) => Some(x + y)
    | (None, Some(y)) => b
    | _ => None
    };
  };

let i_got: (kill, Elf.t, t) => t =
  (num, elf, troll) => {
    modify_score(optional_add(Some(num)), elf, troll);
  };

let i_got_one: (Elf.t, t) => t = i_got(1);

let oops_he_survived: (Elf.t, t) => t = i_got(-1);

let all_elves_of_a_kind_resurrected: (Elf.t, t) => t =
  (elf, troll) => {
    let without_resurected = Killed.remove(elf, troll.kills);
    {name: troll.name, kills: without_resurected};
  };

let all_elves_resurrected: t => t =
  troll => {name: troll.name, kills: Killed.empty};