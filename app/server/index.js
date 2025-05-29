const http = require("http");
const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const CORS = require("cors");

const INTERPRETER_PATH = "..\\..\\Interpreter\\yulang.exe";

const app = express();
const PORT = 9000;
app.use(CORS());

app.use(express.json());
app.post("/", (req, res) => {
  const received_code = req.body.code.split("\n").join(" ");


  
  // fs.writeFileSync('./output_file/output', received_code);
  // const file_content = fs.readFileSync('./output_file/output', 'utf-8');
  
  console.log(received_code)
  const comm = `echo ${received_code} | ${INTERPRETER_PATH}`;
  // console.log(`Executing: ${comm}`);

  exec(comm, (error, stdout, stderr) => {
    if (error) {
      console.error(`error: ${error.name}`);
      // fs.writeFileSync("./output_file/output", error);
    }
    if (stderr) {
      console.error(`stderr: ${stderr}`);
      fs.writeFileSync("./output_file/output", stderr);
    }

    if (!stderr && !error) {
      console.log(stdout);
      fs.writeFileSync("./output_file/output", stdout);
      res.send("sent");
    }
  });
});

app.get("/", (req, res) => {
  const output = fs.readFileSync("./output_file/output", "utf-8");

  // console.log(output);

  res.send(output);

  fs.writeFileSync("./output_file/output", "");
  fs.unlinkSync("./output_file/output", (err) => {
    if (err) throw err;
  });
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
