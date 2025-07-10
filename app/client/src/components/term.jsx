import { useRef } from "react";

export function Terminal( { outputs } ) {
  const outputRef = useRef();

  return (
    <div ref={outputRef} className="output" style={{ maxHeight: "50vh", overflow: "auto", marginInline: "1rem", marginTop:"1rem", marginBottom:"1rem"}}>
      {outputs && outputs.map((output, key) => (
        <div key={key} style={{
          color: key===0 ? "#FFC72C" : "#C6A1CF",
          fontFamily: "monospace",
          fontSize: "1rem",
          marginBottom: "1rem"
        }}>{key===0 ? (">\t\t" + output) : output}</div>
      ))}
    </div>
  );
}
