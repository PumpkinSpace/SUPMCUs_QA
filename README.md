# SUPMCUs_QA
Contains projects used to do the QA.
There will be 4 projects: GPS, BIM, PIM and SIM. Right now they all share the same source files.
They will use those files to perform the general SUPMCU test found in task_supmcu_qa.c.
Each project will also have a defined macro (SUPMCU_XXX_REVX) that will define which address to send commands to,
as well as what is the next task to run: task_gps_qa, task_bim_qa etc.
Child specific task is started at the end of the supmcu_qa test.
