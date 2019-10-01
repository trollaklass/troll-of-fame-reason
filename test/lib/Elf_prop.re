open Framework;
open QCheckRely;

let {describe} = extendDescribe(QCheckRely.Matchers.matchers);

describe("Elf property testing", ({test}) => {
  test("passing test", ({expect}) => {
    let passing =
      QCheck.Test.make(
        ~count=1000,
        ~name="list_rev_is_involutive",
        QCheck.(list(small_int)),
        l =>
        List.rev(List.rev(l)) == l
      );
    expect.ext.qCheckTest(passing);
    ();
  })
});