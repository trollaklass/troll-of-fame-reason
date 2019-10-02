open Framework;
open Lib.Troll;

describe("Troll test suite", ({test}) => {
  test("modify_score should add key faeor with value 1", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_after = modify_score(_opta => Some(1), faeor, aklass_before);
    expect.int(Killed.find(faeor, aklass_after.kills)).toBe(1);
  });
  test("modify_score should remove key", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_with_faeor =
      modify_score(_opta => Some(1), faeor, aklass_before);
    let aklass_without_faeor =
      modify_score(_opta => None, faeor, aklass_with_faeor);
    expect.equal(Killed.find_opt(faeor, aklass_without_faeor.kills), None);
  });
  test("i_got should add key faeor with value 5", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_after = i_got(5, faeor, aklass_before);
    expect.int(Killed.find(faeor, aklass_after.kills)).toBe(5);
  });
  test("i_got_one should add key faeor with value 1", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_after = i_got_one(faeor, aklass_before);
    expect.int(Killed.find(faeor, aklass_after.kills)).toBe(1);
  });
  test("oops_he_survived should remove faeor", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_kills_of_faeor =
      (i_got_one(faeor, aklass_before) |> oops_he_survived(faeor)).kills
      |> Killed.find_opt(faeor);
    expect.equal(aklass_kills_of_faeor, None);
  });
  test("empty kills should score 0", ({expect}) => {
    let aklass = {name: "Aklass", kills: Killed.empty};
    expect.int(scoring(aklass)).toBe(0);
  });
  test("got one when no kill should have one kill", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass = {name: "Aklass", kills: Killed.empty};
    let counter: int = i_got_one(faeor, aklass).kills |> Killed.find(faeor);
    expect.int(counter).toBe(1);
  });
  test("miss them when no kill should have no kill", ({expect}) => {
    let faeor = Lib.Elf.{role: Swordsman, race: DarkElf};
    let aklass = {name: "Aklass", kills: Killed.empty};
    let counter =
      (i_got_one(faeor, aklass) |> oops_he_survived(faeor)).kills
      |> Killed.find_opt(faeor);
    expect.equal(counter, None);
  });
});