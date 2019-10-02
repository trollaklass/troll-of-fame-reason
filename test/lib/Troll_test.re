open Framework;
open Lib.Troll;

describe("Troll test suite", ({test}) => {
  test("modify_score should add key doomshadow with value 1", ({expect}) => {
    let doomshadow = Lib.Elf.{role: Warlock, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_after =
      modify_score(_opta => Some(1), doomshadow, aklass_before);
    expect.int(Killed.find(doomshadow, aklass_after.kills)).toBe(1);
  });
  test("modify_score should remove key", ({expect}) => {
    let doomshadow = Lib.Elf.{role: Warlock, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_with_doomshadow =
      modify_score(_opta => Some(1), doomshadow, aklass_before);
    let aklass_without_doomshadow =
      modify_score(_opta => None, doomshadow, aklass_with_doomshadow);
    expect.equal(
      Killed.find_opt(doomshadow, aklass_without_doomshadow.kills),
      None,
    );
  });
  test("i_got should add key doomshadow with value 5", ({expect}) => {
    let doomshadow = Lib.Elf.{role: Warlock, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_after = i_got(5, doomshadow, aklass_before);
    expect.int(Killed.find(doomshadow, aklass_after.kills)).toBe(5);
  });
  test("i_got_one should add key doomshadow with value 1", ({expect}) => {
    let doomshadow = Lib.Elf.{role: Warlock, race: DarkElf};
    let aklass_before = {name: "Aklass", kills: Killed.empty};
    let aklass_after = i_got_one(doomshadow, aklass_before);
    expect.int(Killed.find(doomshadow, aklass_after.kills)).toBe(1);
  });
  /* test("got one when no kill should have one kill", ({expect}) => {
       let doomshadow = Lib.Elf.{role: Warlock, race: DarkElf};
       let aklass = {name: "Aklass", kills: Killed.empty};
       let counter: int =
         i_got_one(doomshadow, aklass).kills |> Killed.find(doomshadow);
       print_endline(string_of_int(1));
       expect.int(counter).toBe(1);
     });
     test("miss them when no kill should have no kill", ({expect}) => {
       let doomshadow = Lib.Elf.{role: Warlock, race: DarkElf};
       let aklass = {name: "Aklass", kills: Killed.empty};
       let counter =
         (i_got_one(doomshadow, aklass) |> oops_he_survived(doomshadow)).kills
         |> Killed.find(doomshadow);
       expect.int(counter).toBe(0);
     }); */
});