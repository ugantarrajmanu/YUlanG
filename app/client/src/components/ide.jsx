import { useState } from "react";
import { YEditor } from "./editor";
import { Terminal } from "./term";

export function Ide() {
  const [outputs, setOutputs] = useState(["\t\tWelcome to the YUlang!"]);

  const [code, setCode] = useState(
    `arey yug a = "hello" string hai


yug i ko 5 se 10 tak lejana hai {
    yug i likhna hai
} 

yug i likhna hai
yug 50 likhna hai`
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
      <div className="main-editor-container">
        <YEditor onClick={executeCode} code={code} setCode={setCode} />
      </div>
      <div className="main-output-container">
        <Terminal outputs={outputs} />
      </div>
    </>
  );
}
