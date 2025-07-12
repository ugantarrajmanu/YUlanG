import { Ide } from './components/ide'
import './App.css'
import { Documentation } from './components/documentation'
import {  useState } from 'react';


function App() {
  const [vis, setVis] = useState(false)

  return (
    <div className="container" style={{overflow: vis ? "hidden" : "auto"}}>
      <Ide vis={vis} setVis={() => setVis(true)}/>
      { !!vis && (
          <Documentation vis={vis} setVis={() => setVis(false)}/> 
      )}
      
    </div>

  ) 
}


export default App
