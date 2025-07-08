import { Editor } from "@monaco-editor/react";
import { useRef } from "react";


export function Terminal( { outputs } ) {
  const outputRef = useRef();

  console.log(outputs);

  return (
    <div ref={outputRef} className="output" style={{padding: "1rem"}}>
      {outputs && outputs.map((output, key) => (
        <div key={key} style={{
          color: "violet",
          fontFamily: "monospace",
          fontSize: "1rem",
          marginBottom: "1rem"
        }}>{">\t\t" + output}</div>
      ))}
    </div>
  );
}
