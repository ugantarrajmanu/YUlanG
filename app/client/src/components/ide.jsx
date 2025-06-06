import { useState } from "react";
import { YEditor } from "./editor";
import { Terminal } from "./term";


const OUTPUT_PATH = "../server/output_file/output";
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
    const res = await fetch("https://yulang-back.onrender.com/api", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ code: code }),
    })

    const data = (await res.text()).split("\r\n");
    data.pop() 

    setOutputs(["Executing", ...data]);
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
