// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp
// See the 'F# Tutorial' project for more help.

// Define a function to construct a message to print
let from whom =
    sprintf "from %s" whom

[<EntryPoint>]
let main argv =
    let message = from "F# LogicGate2"
    printfn "F# Logic Gates %s" message
    
    let NOT a = not a
    let AND a b = a && b
    let OR a b = a || b
    let XOR a b = a <> b

    let a = true
    let b = true

    let y = NOT a
    printfn "%b" y

    let y = AND a b
    printfn "%b" y

    let y = OR a b
    printfn "%b" y

    let y = XOR a b
    printfn "%b" y

    0 // return an integer exit code
