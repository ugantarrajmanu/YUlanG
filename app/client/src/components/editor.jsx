import Editor from "@monaco-editor/react";
import "./editor.css";

export const YEditor = ({ onClick, code, setCode, setVis }) => {


  return (
    <div className="second-editor-container">
      <div className="header">
        <div style={{ display: "flex", alignItems: "center", gap: "1rem" }}>
          <h1 role="button" className="yulang">YUlanG</h1>
          <button className='manual-button' onClick={() => setVis(true)}>?</button>
        </div>
        <button className="run-button" title="run" onClick={onClick}>
          Run
        </button>
      </div>
      <div className="editor-container" style={{ backgroundColor: "#000000" }}>
        <Editor
          className="code-editor"
          theme="hc-black"
          defaultValue={code}
          onChange={(code) => {
            setCode(code);
          }}
        />
      </div>
    </div>
  );
};
