/* sample Fame program */
open Lib.Elf;
open Lib.Troll;
open Lib.Util;
/* targets */
let archer_de = {role: Archer, race: DarkElf};
let warlock_de = {role: Warlock, race: DarkElf};
let swordsman_de = {role: Swordsman, race: DarkElf};
let priest_he = {role: Priest, race: HighElf};
let swordsman_he = {role: Swordsman, race: HighElf};

/* trolls */
let aklass =
  {name: "Aklass", kills: Killed.empty}
  |> i_got(5, warlock_de)
  |> i_got(2, priest_he)
  |> i_got(20, swordsman_de)
  |> i_got(10, archer_de);
let lesglandes =
  {name: "Lesglandes", kills: Killed.empty}
  |> i_got_one(priest_he)
  |> oops_he_survived(priest_he)
  |> i_got(5, warlock_de)
  |> all_elves_of_a_kind_resurrected(warlock_de);

let lesklat =
  {name: "Lesklat", kills: Killed.empty}
  |> i_got_one(priest_he)
  |> i_got(20, swordsman_he)
  |> i_got(2, priest_he)
  |> i_got_one(swordsman_he)
  |> i_got_one(warlock_de)
  |> oops_he_survived(warlock_de);

let tyneth =
  {name: "Tyneth", kills: Killed.empty}
  |> i_got_one(priest_he)
  |> i_got(5, swordsman_de);
let warband = [aklass, lesglandes, lesklat, tyneth];
print_warband(warband);