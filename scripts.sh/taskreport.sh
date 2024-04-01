#!/bin/bash


# Path to the file storing task entries
TASK_LOG="$HOME/Desktop/Capstone/task_log.txt"


# Function to record the start time of a task
start_task() {
   task_name="$1"
   start_time=$(date "+%Y-%m-%d %H:%M:%S")
   echo "$task_name|$start_time" >> "$TASK_LOG"
   echo "Task '$task_name' started at $start_time."
}


# Function to record the end time of a task
end_task() {
   task_name="$1"
   end_time=$(date '+%Y-%m-%d %H:%M:%S')
   echo "$task_name|$end_time" >> "$TASK_LOG"
   echo "Task '$task_name' ended at $end_time."
}


# Function to generate a report on time spent
generate_report() {
   echo "Task Report:"
   echo "----------"


   while IFS='|' read -r task_name start_time; do
       end_time=$(tail -n 1 "$TASK_LOG" | grep "$task_name" | cut -d '|' -f 2)
       if [ -n "$end_time" ]; then
           start_seconds=$(date -d "$start_time" '+%s')
           end_seconds=$(date -d "$end_time" '+%s')
           duration=$((end_seconds - start_seconds))


           printf "Task: %-20s Duration: %02d:%02d:%02d\n" "$task_name" $((duration / 3600)) $(((duration % 3600) / 60)) $((duration % 60))
       fi
   done < "$TASK_LOG"
}


# Function to run continuously, checking for task completion and generating reports
continuous_execution() {
   while true; do
       end_task_check
       generate_report
       sleep 300  # Wait for 5 minutes before checking again
   done
}


# Function to check if tasks have ended and update the log file
end_task_check() {
   while IFS='|' read -r task_name start_time; do
       end_time=$(tail -n 1 "$TASK_LOG" | grep "$task_name" | cut -d '|' -f 2)
       if [ -n "$end_time" ]; then
           continue
       else
           end_task "$task_name"
       fi
   done < "$TASK_LOG"
}


# Start continuous execution
continuous_execution
