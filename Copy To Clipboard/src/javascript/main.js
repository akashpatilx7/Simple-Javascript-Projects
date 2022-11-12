// Two Constant References to Two Elements

const myInp=document.getElementById("myInp");
const btnCopy=document.getElementById("btnCopy");

btnCopy.onclick=function(){
  // Step 1 : Select the text.
  myInp.select();

  // Step 2 : Copying the text.
  document.execCommand("Copy"); // This command (execCommand) copies the selected text to the clipboard. 
  
  // NOTE : The reason of working of the execCommand on the input field is it has SELECT Method. On the other hand, We cannot just say/ use "element.select"
};