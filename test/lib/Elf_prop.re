open Framework;
open QCheckRely;
open Generator.Fantasy;
open Lib.Elf;

let {describe} = extendDescribe(QCheckRely.Matchers.matchers);

/* Porperties Based Tests */
describe("Elf Invariance", ({test}) => {
  test("Elf value should always be positive", ({expect})
    => {
      QCheck.Test.make(
        ~count=1000,
        ~name="elf value should always be positive",
        elf_arbitrary,
        elf =>
        value(elf) > 0
      )
      |> expect.ext.qCheckTest;
      ();
    })
    /* test("Elf value should always be the product of race and role", ({expect}) => {
         QCheck.Test.make(
           ~count=1000,
           ~name="Elf value should always be the product of race and role",
           elf_arbitratry,
           elf =>
           value(elf) == race_to_enum(elf.race) * role_to_enum(elf.role)
         )
         |> expect.ext.qCheckTest;
         ();
       }); */
});