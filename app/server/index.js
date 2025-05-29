const http = require("http");
const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const CORS = require("cors");

const INTERPRETER_PATH = "yulang.exe";

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());

app.post("/api", (req, res) => {
  const received_code = req.body.code.split("\n").join(" ");

  const comm = `echo ${received_code} | ${INTERPRETER_PATH} > output`;

  exec(comm, (error, stdout, stderr) => {
    const output = fs.readFileSync("output");

    res.send(output);

    fs.writeFileSync("output", "");
    fs.unlinkSync("output", (err) => {
      if (err) throw err;
    });

  });
});

app.get("/api", (req, res) => {
  res.send("Server Running.....");
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
