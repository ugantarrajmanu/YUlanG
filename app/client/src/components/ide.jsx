import { useState } from "react";
import { YEditor } from "./editor";
import { Terminal } from "./term";

export function Ide({ setVis }) {
  const [outputs, setOutputs] = useState(["\t\tWelcome to the YUlang!"]);

  const [code, setCode] = useState(
    `arey yug a = "Hello Butterflies" string hai

yug i ko 0 se 3 tak lejana hai {
    yug agar (i%2 == 0) hai to {
        yug a likhna hai
    } nahi to {
        yug "Bye Butterflies" likhna hai
    }
}

arey yug b = 0 int hai

yug i ko 0 se 5 tak lejana hai {
    b = b + 5 hai
}
yug b likhna hai`
  );

  const executeCode = async () => {
    fetch("https://yulang-server.onrender.com/api/yulang", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ code: code }),
    })
    .then(res => res.text())
    .then(data => { console.log(data); return data.split("\n")})
    .then(data => { data.pop(); return setOutputs(["Executing", ...data]); })
    .catch(err => console.log(err));
  };

  return (
    <>
      <div className="main-editor-container" >
        <YEditor onClick={executeCode} code={code} setCode={setCode} setVis={setVis}/>
      </div>
      <div className="main-output-container">
        <Terminal outputs={outputs} />
      </div>
    </>
  );
}
