#ifndef MULTILEVELFEEDBACKQUEUE_H
#define MULTILEVELFEEDBACKQUEUE_H
/*This scheduler is so bad I didn't want it associated with the working schedulers.
  so I ended up making a separate header file just for multilevel feedback queue.
*/

void PCBqueue::MLFQ(std::deque<PCB*> processList){
    //sort by time arrival and execute by time quantum
    std::ofstream mlfq_file;
    mlfq_file.open("mlfq.txt");
    struct PCB* tempPCB = new PCB;
    struct PCB* compPCB = new PCB;
    int TIME_QUANTUM = 0;
    int totalTime = 0;
    int timeElapsed = 0;
    int decrementarrivaltime = 0;
    int timeout = 0;
    int NUMBER_OF_QUEUES = 0;
    int PRIORITY_BOOST = 0;
    int counter = 0;
    int offset = 0;
    bool stop = false;
    bool done = false;
    std::deque<PCB*> outputlist;
    //prompt user for time quantum
    std::cout<<"\tEnter number of queues: ";
    std::cin>>NUMBER_OF_QUEUES;
    std::cout<<"\tEnter time quantum: ";
    std::cin>>TIME_QUANTUM;
    std::cout<<"\tEnter time for priority boost: ";
    std::cin>>PRIORITY_BOOST;
    while(!done){
    //look to see if time to update for priority boost
    if(timeElapsed%PRIORITY_BOOST == 0 && timeElapsed > 0){//set all priorities to highest level
      if(!outputlist.empty()){
        for(int i = 0; i < outputlist.size(); i++){
            tempPCB = outputlist.at(i);
            if(tempPCB->p_t_remain > 0){
                tempPCB->p_priority = tempPCB->p_priority + NUMBER_OF_QUEUES;//increments priorities to top of "queues"
            }}}}
        //see if there are new processes to schedule:
        if(!processList.empty()){
        for(int i=0; i<processList.size(); i++){
            compPCB = processList.at(i);
            if(compPCB->p_t_arriv <= 0){//time to enqueue process into ready queue
                outputlist.push_back(compPCB);
                processList.erase(processList.begin()+i);}
            else{compPCB->p_t_arriv = compPCB->p_t_arriv - 1;}//std::cout<<compPCB->p_t_arriv<<",";}
            }}

        //if the time quantum is up, go through ready list and find process with highest priority
        if(timeElapsed%TIME_QUANTUM == 0){
            //for(int i = 0; i < outputlist.size(); i++){}
            //decrementarrivaltime++;
            stop = false; //keep reading queue to find process with time remaining
            counter = 0; //start at front of queue
            while(!stop){
                compPCB = outputlist.at(0);
                tempPCB = outputlist.at(counter);
                if(tempPCB->p_priority > compPCB->p_priority){outputlist.erase(outputlist.begin()+counter);outputlist.push_front(tempPCB);} //break out of loop if process has time remaining
                if(counter == outputlist.size()){stop = true;} //defaut stop if all processes are finished
                counter++;
                }
            tempPCB = outputlist.at(0);
            tempPCB->p_t_remain = tempPCB->p_t_remain - TIME_QUANTUM;
            tempPCB->p_priority--;
            //remove from front and attach to back of queue
            outputlist.push_back(tempPCB);
            outputlist.erase(outputlist.begin());
            }
        //check to see if any processes are left to execute
        done = false;
        for(int i = 0; i < outputlist.size(); i++){//this for loop determines if entire queue is finished
            compPCB= outputlist.at(i);
            if(compPCB->p_t_remain > 0){break;}
            if(i == (outputlist.size()-1)){done = true; break;}//we searched through entire list and no processes are left
            }
        timeElapsed++;
        totalTime++;}
    //return outputlist;
    if(mlfq_file.is_open()){
        for(int i = 0; i < outputlist.size(); i++){
        compPCB = outputlist.at(i);
        mlfq_file<<compPCB->p_name<<"\n";}
        mlfq_file<<"\ntotal time to completion: "<<totalTime
                <<"\naverage turnaround time: "<<(totalTime/outputlist.size())
                <<"\nTime quantum: "<<TIME_QUANTUM;
        mlfq_file.close();
        std::cout<<"File was written successfully!";}
    else{std::cout<<"\nError! Could not write to file.";}
    return;
}

#endif // MULTILEVELFEEDBACKQUEUE_H
