[@deriving (show, enum, eq, ord)]
type race =
  | [@value 1] DarkElf
  | [@value 2] HighElf; /* Because everybody hates those smug High Elves */

[@deriving (show, enum, eq, ord)]
type role =
  | [@value 1] Swordsman
  | [@value 2] Archer
  | [@value 5] Priest
  | [@value 4] Warlock;

[@deriving (show, eq, ord)]
type t = {
  role,
  race,
};

let value = elf => role_to_enum(elf.role) + race_to_enum(elf.race);
let from_pair = ((role, race)) => {race, role};