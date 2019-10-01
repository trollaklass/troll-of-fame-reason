open Framework;
open Lib.Troll;

describe("Troll test suite", ({test}) => {
  test("got one when no kill should have one kill", ({expect}) => {
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
  });
});