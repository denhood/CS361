#ifndef OSSCHEDULER_H
#define OSSCHEDULER_H

///shortest job first----------------------------------------------------------
//std::deque<PCB*> PCBqueue::SJF(std::deque<PCB*> processlist){
void PCBqueue::SJF(std::deque<PCB*> processlist){
    std::ofstream sjf_file;
    sjf_file.open("sjf.txt");
    PCB* tempPCB = new PCB;
    PCB* compPCB = new PCB;
    bool stop = false;
    int offset = 0;
    int totalTime =0;
    std::deque<PCB*> outputlist;

    /*for(int i =0; i< processlist.size(); i++){
        tempPCB = processlist.at(i);
        if(outputlist.empty()==true){outputlist.push_back(tempPCB);}
        else{
            for(int j=0;j < outputlist.size();j++){
                compPCB = outputlist.at(j);
                if(tempPCB->p_t_remain < compPCB->p_t_remain){
                    outputlist.emplace(outputlist.begin()+j,tempPCB);}}}
    return outputlist;}*/
    while(processlist.empty() != true){
        tempPCB = processlist.at(0); //grab node at front of list
        offset = 0;
        for(int i=0; i<processlist.size(); i++){
            compPCB = processlist.at(i);
            if(compPCB->p_t_remain < tempPCB->p_t_remain){tempPCB = compPCB; offset = i;}}
        processlist.erase(processlist.begin()+offset);
        outputlist.push_back(tempPCB);}
    //return outputlist;
    if(sjf_file.is_open()){
        for(int i = 0; i < outputlist.size(); i++){
        compPCB = outputlist.at(i);
        totalTime = compPCB->p_t_remain + totalTime;
        compPCB->p_t_remain = 0;
        sjf_file<<compPCB->p_name<<"\n";}
        sjf_file<<"\ntotal time to completion: "<<totalTime
                <<"\naverage turnaround time: "<<(totalTime/outputlist.size());
        sjf_file.close();
        std::cout<<"File was written successfully to sjf.txt";}
    else{std::cout<<"\nError! Could not write to file.";}
    //delete temporary pointers
    tempPCB = NULL;
    compPCB = NULL;
    delete tempPCB;
    delete compPCB;
    }

///first in first out----------------------------------------------------------
void PCBqueue::FIFO(std::deque<PCB*> processlist){
    //sort by time of arrival
    std::ofstream fifo_file;
    fifo_file.open("fifo.txt");
    struct PCB* tempPCB = new PCB;
    struct PCB* compPCB = new PCB;
    bool stop = false;
    int offset = 0;
    int totalTime = 0;
    std::deque<PCB*> outputlist;
    while(processlist.empty() != true){
        tempPCB = processlist.at(0); //grab node at front of list
        offset = 0;
        for(int i=0; i<processlist.size(); i++){
            compPCB = processlist.at(i);
            if(compPCB->p_t_arriv < tempPCB->p_t_arriv){tempPCB = compPCB; offset = i;}}
        processlist.erase(processlist.begin()+offset);
        outputlist.push_back(tempPCB);}
    //return outputlist;
    if(fifo_file.is_open()){
        for(int i = 0; i < outputlist.size(); i++){
        compPCB = outputlist.at(i);
        //totalTime = compPCB->p_t_remain + totalTime;
        //compPCB->p_t_remain = 0;
        fifo_file<<compPCB->p_name<<"\n";
        totalTime += compPCB->p_t_remain;}//increment time
        fifo_file<<"\ntotal time to completion: "<<totalTime
                <<"\naverage turnaround time: "<<(totalTime/outputlist.size());
        fifo_file.close();
        std::cout<<"File was written successfully to fifo.txt";}
    else{std::cout<<"\nError! Could not write to file.";}
    //delete temporary pointers
    tempPCB = NULL;
    compPCB = NULL;
    delete tempPCB;
    delete compPCB;
    }

///shortest time to completion first-------------------------------------------
void PCBqueue::STCF(std::deque<PCB*> processlist){
    //sort by time remaining
    std::ofstream stcf_file;
    stcf_file.open("stcf.txt");
    PCB* tempPCB = new PCB;
    PCB* compPCB = new PCB;
    PCB* procPCB = new PCB;
    bool stop = false;
    int totalTime = 0; //total runtime of scheduler
    int offset = 0;
    int time = 0;
    int timeout = 0;
    std::deque<PCB*> outputlist;
    while(!stop){//!processlist.empty() && timeout < 100){//} != true){
        for(int i=0; i<processlist.size(); i++){//look at unprocessed nodes
            compPCB = processlist.at(i);
            if(compPCB->p_t_arriv <= 0){//current process has arrived!
                //case if output deque is empty
                if(outputlist.size() == 0){outputlist.push_back(compPCB);processlist.erase(processlist.begin()+i);
                    //std::cout<<"after first PCB is added, input size="<<processlist.size()<<" output="<<outputlist.size();
                    }
                else{
                //std::cout<<"\nprocess "<<compPCB->p_name<<" has time arrival of "<<compPCB->p_t_arriv;
                //need to place newly arrived process in non empty deque according to t_remain
                for(int k = 0; k < outputlist.size(); k++){
                    tempPCB=outputlist.at(k);
                    if(compPCB->p_t_remain < tempPCB->p_t_remain){
                    //std::cout<<compPCB->p_name<<"has a time remaining less than "<<tempPCB->p_name<<std::endl;
                        //outputlist.push_back(compPCB);
                        outputlist.insert(outputlist.begin()+k,compPCB);//insert in location of queue according to t_remain
                        break;}
                    //if(k == (outputlist.size()-1)){outputlist.push_back(compPCB);}
                    }
                processlist.erase(processlist.begin()+i);
                }}//remove process from input queue
            else{compPCB->p_t_arriv = compPCB->p_t_arriv - 1;}//std::cout<<compPCB->p_t_arriv<<",";}
            //std::cout<<"one iteration search\n";
            }
            if(!outputlist.empty()){
                for(int i = 0; i < outputlist.size(); i++){
                    procPCB = outputlist.at(i);
                    if(procPCB->p_t_remain > 0){procPCB->p_t_remain--;break;}
                    if(processlist.empty() && i == (outputlist.size()-1)){stop = true;}}}
        time++;
        timeout++;}
    //return outputlist;
    if(stcf_file.is_open()){
        for(int i = 0; i < outputlist.size(); i++){
        compPCB = outputlist.at(i);
        //totalTime = compPCB->p_t_remain + totalTime;
        //compPCB->p_t_remain = 0;
        stcf_file<<compPCB->p_name<<"\n";
        totalTime +=compPCB->p_t_remain;}
        stcf_file<<"\ntotal time to completion: "<<totalTime
                <<"\naverage turnaround time: "<<(totalTime/outputlist.size());
        stcf_file.close();
        std::cout<<"File was written successfully to stcf.txt";}
    else{std::cout<<"\nError! Could not write to file.";}
    //delete temporary pointers
    tempPCB = NULL;
    compPCB = NULL;
    procPCB = NULL;
    delete tempPCB;
    delete compPCB;
    delete procPCB;
    }

///fixed priority preemptive scheduling----------------------------------------
void PCBqueue::FPPS(std::deque<PCB*> processlist){std::cout<<"Here inside fixed priority";}

///round robin scheduling------------------------------------------------------
void PCBqueue::RR(std::deque<PCB*> processlist){
    //sort by time arrival and execute by time quantum
    int TIME_QUANTUM = 0;
    std::ofstream rr_file;
    rr_file.open("rr.txt");
    PCB* tempPCB = new PCB;
    PCB* compPCB = new PCB;
    int totalTime = 0;
    int timeElapsed = 1;
    int decrementarrivaltime = 0;
    int timeout = 0;
    bool stop = false;
    bool done = false;
    int counter = 0;
    int offset = 0;
    std::deque<PCB*> outputlist;
    //prompt user for time quantum
    std::cout<<"\tEnter time quantum: ";
    std::cin>>TIME_QUANTUM;
    std::cin.ignore(); //ignore "\n" left in cin input buffer
    while(!done){
    //while(stop !=true){
        if(processlist.size() != 0){
        for(int i=0; i<processlist.size(); i++){
            compPCB = processlist.at(i);
            //std::cout<<compPCB->p_name<<compPCB->p_t_arriv<<std::endl;
            //compPCB->p_t_arriv = compPCB->p_t_arriv - 1;
            if(compPCB->p_t_arriv <= 0){
                //std::cout<<"enqueing: "<<compPCB->p_name<<" time elapsed: "<<timeElapsed<<std::endl;
                //while(compPCB->p_t_remain >=
                //for(int k = 0; k < outputlist.size(); k++){
                //    tempPCB=outputlist.at(k);
                //    if(compPCB->p_t_remain < tempPCB->p_t_remain){
                //        outputlist.insert(outputlist.begin()+k,compPCB);}}
                outputlist.push_back(compPCB);
                processlist.erase(processlist.begin()+i);}
            else{compPCB->p_t_arriv = compPCB->p_t_arriv - 1;}//std::cout<<compPCB->p_t_arriv<<",";}
            }}
        //for(int j = 0; j<outputlist.size(); j++){
        //    tempPCB = outputlist.at(0);
        //    if(tempPCB->p_t_remain >0){
        //        tempPCB->p_t_remain--;}
            //tempPCB->p_t_remain--;

        //std::cout<<std::endl;

        if(timeElapsed%TIME_QUANTUM == 0){
            //std::cout<<"time:"<<decrementarrivaltime;
            decrementarrivaltime++;
            stop = false; //keep reading queue to find process with time remaining
            counter = 0; //start at front of queue
            //tempPCB = new PCB;
            while(stop != true){
                tempPCB = outputlist.at(counter);
                if(tempPCB->p_t_remain > 0){break;} //break out of loop if process has time remaining
                if(counter == outputlist.size()){stop = true;} //defaut stop if all processes are finished
                counter++;
                }

            //if(tempPCB->p_t_remain <= 0){
            //    outputlist.erase(processlist.begin());
            //    outputlist.push_back(tempPCB);
            //    tempPCB = outputlist.at(0);}
        tempPCB->p_t_remain = tempPCB->p_t_remain - TIME_QUANTUM;
        //remove from front and attach to back of queue
        outputlist.push_back(tempPCB);
        outputlist.erase(outputlist.begin()+counter);
        }
        done = false;//reset done before exit while loop
        for(int i = 0; i < outputlist.size(); i++){//this for loop determines if entire queue is finished
            compPCB= outputlist.at(i);
            if(compPCB->p_t_remain > 0){break;}//= tempPCB->p_t_remain - TIME_QUANTUM;
            if(i == (outputlist.size()-1)){done = true; break;}
            }
        //timeout++;
        //outputlist.push_back(tempPCB);
        timeElapsed++;
        timeout++;}

    //return outputlist;
    if(rr_file.is_open()){
        for(int i = 0; i < outputlist.size(); i++){
        compPCB = outputlist.at(i);
        //totalTime = compPCB->p_t_remain + totalTime;
        //compPCB->p_t_remain = 0;
        rr_file<<compPCB->p_name<<"\n";}
        rr_file<<"\ntotal time to completion: "<<timeElapsed
                <<"\naverage turnaround time: "<<(timeElapsed/outputlist.size())
                <<"\nTime quantum: "<<TIME_QUANTUM;
        rr_file.close();
        std::cout<<"File was written successfully to rr.txt";}
    else{std::cout<<"\nError! Could not write to file.";}
    //delete temporary pointers
    tempPCB = NULL;
    compPCB = NULL;
    delete tempPCB;
    delete compPCB;}

///multi level feedback queue--------------------------------------------------
    //see multilevelfeedbackqueue.h
///lottery scheduling----------------------------------------------------------
void PCBqueue::LS(std::deque<PCB*> processlist){
    int NUMBER_OF_TICKETS = 0;
    std::ofstream ls_file;
    ls_file.open("ls.txt");
    PCB* tempPCB = new PCB;
    PCB* compPCB = new PCB;
    int totalTime = 0;
    //int timeElapsed = 1;
    //int counter = 0;
    int offset = 0;
    int CPU_count = 0;
    bool done = false;
    std::deque<PCB*> outputlist;
    //random number generator for tickets:
    srand (time(NULL));
    //prompt user for tickets
    std::cout<<"\tEnter number of tickets: ";
    std::cin>>NUMBER_OF_TICKETS;
    std::cin.ignore(); //ignore "\n" left in cin input buffer
    while(!done){
        while(!processlist.empty()){
        tempPCB = processlist.at(0); //grab node at front of list
        offset = 0;
        for(int i=0; i<processlist.size(); i++){
            compPCB = processlist.at(i);
            if(compPCB->p_t_arriv < tempPCB->p_t_arriv){tempPCB = compPCB; offset = i;}}
        processlist.erase(processlist.begin()+offset);
        outputlist.push_back(tempPCB);}

        if(!outputlist.empty()){//go through list add up %CPU
                for(int i = 0; i < outputlist.size(); i++){
                    tempPCB = outputlist.at(i);
                    CPU_count += tempPCB->p_CPU; }
        done = true;
    }
    }
    if(ls_file.is_open()){
        for(int i = 0; i < outputlist.size(); i++){
        compPCB = outputlist.at(i);
        //totalTime = compPCB->p_t_remain + totalTime;
        //compPCB->p_t_remain = 0;
        ls_file<<compPCB->p_name<<"\n";
        totalTime += compPCB->p_t_remain;}//increment time
        ls_file<<"\ntotal time to completion: "<<totalTime
                <<"\naverage turnaround time: "<<(totalTime/outputlist.size())
                <<"\nnumber of tickets:"<<NUMBER_OF_TICKETS;
        ls_file.close();
        std::cout<<"File was written successfully to ls.txt";}
    else{std::cout<<"\nError! Could not write to file.";}
    //delete temporary pointers
    tempPCB = NULL;
    compPCB = NULL;
    delete tempPCB;
    delete compPCB;
}

#endif // OSSCHEDULER_H
