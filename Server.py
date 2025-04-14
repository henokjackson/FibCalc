from fastapi import FastAPI
import subprocess

server = FastAPI()

@server.get("/calculate/{range}")
async def CalculateFibonacci(range: int):
	output = subprocess.run(["/app/Fibonacci", "--range="+str(range)], capture_output=True, text=True)
	return output.stdout.split("\n\n")[1];
