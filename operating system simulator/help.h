#ifndef HELP_H
#define HELP_H
/*This file contains the parser, enumerations and messages of the help file
  I wasn't sure how to return multiple different enumerations so I created
  a new one that has every possible help topic with an 'H_' preceeding
  the command for the help parser.*/

enum help{H_QUIT, H_VERSION, H_HELP, H_DATE, H_SUSPEND, H_RESUME, H_PRIORITY,
          H_SHOWPCB, H_SHOWALL, H_SHOWREADY, H_SHOWBLOCKED, H_SCHEDULER,
          H_SHORTESTJOBFIRST, H_FIRSTINFIRSTOUT, H_SHORTESTTIMETOCOMPLETIONFIRST,
          H_FIXEDPRIORITYPREEMPTIVE, H_ROUNDROBIN, H_MULTILEVELFEEDBACKQUEUE,
          H_LOTTERY, H_FIRSTFIT, H_NEXTFIT, H_BESTFIT, H_WORSTFIT, H_COMMANDNOTFOUND};

help parseHelpString(std::string input){
    if(input == "version"){return H_VERSION;}
    if(input == "quit"){return H_QUIT;}
    if(input == "help"){return H_HELP;}
    if(input == "date"){return H_DATE;}
    if(input == "suspend"){return H_SUSPEND;}
    if(input == "resume"){return H_RESUME;}
    if(input == "priority"){return H_PRIORITY;}
    if(input == "show PCB"){return H_SHOWPCB;}
    if(input == "show all"){return H_SHOWALL;}
    if(input == "show ready"){return H_SHOWREADY;}
    if(input == "show blocked"){return H_SHOWBLOCKED;}
    if(input == "scheduler"){return H_SCHEDULER;}
    if(input == "shortest job first"){return H_SHORTESTJOBFIRST;}
    if(input == "first in first out"){return H_FIRSTINFIRSTOUT;}
    if(input == "shortest time to competion first"){return H_SHORTESTTIMETOCOMPLETIONFIRST;}
    if(input == "fixed priority preemptive"){return H_FIXEDPRIORITYPREEMPTIVE;}
    if(input == "round robin"){return H_ROUNDROBIN;}
    if(input == "multilevel feedback queue"){return H_MULTILEVELFEEDBACKQUEUE;}
    if(input == "lottery"){return H_LOTTERY;}
    if(input == "best fit"){return H_BESTFIT;}
    if(input == "first fit"){return H_FIRSTFIT;}
    if(input == "next fit"){return H_NEXTFIT;}
    if(input == "worst fit"){return H_WORSTFIT;}
    else{return H_COMMANDNOTFOUND;}
}

void get_help(std::string in){
    int command;
    command = parseHelpString(in);
    switch(command){
    case H_QUIT:
        std::cout<<"Type 'quit' to exit, you will be prompted before exit\n";
        break;
    case H_VERSION:
        std::cout<<"Prints the most recent version of DENIX.\n";
        break;
    case H_HELP:
        std::cout<<"This is the help function. Enter the command you wish to inquire about when \nprompted after typing 'help'\n";
        break;
    case H_DATE:
        std::cout<<"Type 'date' to get current date in MM/DD/YYYY format.\n";
        break;
    case H_SUSPEND:
        std::cout<<"Type 'suspend' and then follow the prompt to suspend a PCB.\n";
        break;
    case H_RESUME:
        std::cout<<"Type 'resume' and follow the prompt to resume a PCB.\n";
        break;
    case H_PRIORITY:
        std::cout<<"Type 'priority' to set the priority of a PCB.\n";
        break;
    case H_SHOWPCB:
        std::cout<<"Type 'show PCB' then follow the prompt to see information on PCB.\n";
        break;
    case H_SHOWALL:
        std::cout<<"Type 'show all' to see all PCBs in all queues.\n";
        break;
    case H_SHOWREADY:
        std::cout<<"Type 'show ready' to see all PCBs in the ready queue.\n";
        break;
    case H_SHOWBLOCKED:
        std::cout<<"Type 'show blocked' to see all PCBs in blocked queue.\n";
        break;
    case H_SCHEDULER:
        std::cout<<"Type 'scheduler' then type the name of scheduler you wish to use at the prompt.\n"
                 <<"schedulers are: 'shortest job first', 'first in first out', 'round robin',\n"
                 <<"\t'fixed priority preemptive', 'shortest time to completion first',\n"
                 <<"\t'multilevel feedback queue', or 'lottery'\n";
        break;
    case H_SHORTESTJOBFIRST:
        std::cout<<"Type 'shortest job first' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt.\nOutput file is saved as sjf.txt\n";
        break;
    case H_FIRSTINFIRSTOUT:
        std::cout<<"Type 'first in first out' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt. \nOutput file is saved as fifo.txt\n";
        break;
    case H_SHORTESTTIMETOCOMPLETIONFIRST:
        std::cout<<"Type 'shortest time to completion first' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt. \nOutput file is saved as stcf.txt\n";
        break;
    case H_FIXEDPRIORITYPREEMPTIVE:
        std::cout<<"Type 'fixed priority preemptive' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt. \nOutput file is saved as fpps.txt\n";
        break;
    case H_ROUNDROBIN:
        std::cout<<"Type 'round robin' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt. \nOutput file is saved as rr.txt\n";
        break;
    case H_MULTILEVELFEEDBACKQUEUE:
        std::cout<<"Type 'multilevel feedback queue' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt. \nOutput file is saved as mlfq.txt\n";
        break;
    case H_LOTTERY:
        std::cout<<"Type 'lottery' at the scheduler prompt.\n"
                 <<"Then enter the file you wish to process at the prompt. \nOutput file is saved as ls.txt\n";
        break;
    case H_FIRSTFIT:
        std::cout<<"first fit\n";
        break;
    case H_NEXTFIT:
        std::cout<<"next fit\n";
        break;
    case H_BESTFIT:
        std::cout<<"best fit\n";
        break;
    case H_WORSTFIT:
        std::cout<<"worst fit\n";
        break;
    case H_COMMANDNOTFOUND:
        std::cout<<"command not found.\n";
        break;
    default:
        std::cout<<"bad input!\n";
        break;}
    }

#endif // HELP_H
