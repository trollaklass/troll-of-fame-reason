open Framework;
open Lib.Elf;

describe("Elf test suite", ({test}) => {
  test("2 Warlock Dark Elves should be equal", ({expect}) => {
    let doomshadow = {role: Warlock, race: DarkElf};
    let thundershade = {role: Warlock, race: DarkElf};
    expect.bool(thundershade == doomshadow).toBe(true);
  });

  test(
    "1 Archer Dark Elf and 1 Swordsman High Elf should be equal", ({expect}) => {
    let faeor = {role: Swordsman, race: HighElf};
    let shadowblight = {role: Archer, race: DarkElf};
    expect.int(value(shadowblight)).toBe(value(faeor));
  });
});