// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp
// See the 'F# Tutorial' project for more help.

// Define a function to construct a message to print
let from whom =
    sprintf "from %s" whom

[<EntryPoint>]
let main argv =
    let message = from "F# LogicCircuits1" 
    printfn "Logic Circuit Simulator %s\n" message
    
    let NOT a = not a
    let AND a b = a && b
    let OR a b = a || b
    let XOR a b = a <> b
    let NAND a b = AND a b |> NOT
    let NOR a b = OR a b |> NOT
    let NXOR a b = XOR a b |> NOT
    
    //Half Adder
    let HA a b =
        let s = XOR a b // one xor gate
        let c = AND a b // one and gate
        (s, c)          // retrims sum and carry
        
    //Full Adder
    let FA a b cin = 
        let (s1, c1) = HA a b     // first half adder
        let (sum, c2) = HA s1 cin // second half adder
        let cout = OR c1 c2       // or gate for the 2 carry out
        (sum, cout)

    printf "Half Adder Truth Table \n"
    printf  "   A     B      S     C  \n"
    let (s, c) = HA false false
    printfn " false false  %b %b"  s c
    let (s, c) = HA false true
    printfn " false true   %b  %b" s c
    let (s, c) = HA true false
    printfn " true  false  %b  %b" s c
    let (s, c) = HA true true
    printfn " true  true   %b %b\n"  s c

    printf "Full Adder Truth Table \n"
    printf  "   A     B    Cin    Sum   Cout  \n"
    let (sum, cout) = FA false false false
    printfn " false false false  %b %b " sum cout
    let (sum, cout) = FA false false true
    printfn " false false true   %b  %b" sum cout
    let (sum, cout) = FA false true false
    printfn " false true  false  %b  %b" sum cout
    let (sum, cout) = FA false true true
    printfn " false true  false  %b %b"  sum cout
    let (sum, cout) = FA true false false
    printfn " true  false false  %b  %b"  sum cout
    let (sum, cout) = FA true false true
    printfn " true  false true   %b %b"  sum cout
    let (sum, cout) = FA true true false
    printfn " true  true  false  %b %b"  sum cout
    let (sum, cout) = FA true true true
    printfn " true  true  true   %b  %b"  sum cout

    0 // return an integer exit code
