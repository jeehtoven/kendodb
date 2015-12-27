#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdexcept>

using namespace std;

//Function to update configuration file parameter value.

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


int main()
{

//Linux specific system call. Comment this line out if on Windows.
system("clear");

//Main Menu
cout << "Welcome to Kendo!" << endl;
cout << "Please select an option from the menu." << endl;
cout << "1. SELECT" << endl;
cout << "2. UPDATE" << endl;
cout << "3. DELETE" << endl;
cout << "4. INSERT INTO" << endl;
cout << "5. CREATE DATABASE" << endl;
cout << "6. ALTER DATABASE" << endl;
cout << "7. CREATE TABLE" << endl;
cout << "8. ALTER TABLE" << endl;
cout << "9. DROP TABLE" << endl;
cout << "10. CREATE INDEX" << endl;
cout << "11. DROP INDEX" << endl;
cout << "Your selection: ";

//Declarations
string name;
string directory;
string result;
int choice;
int alter;
string alter_name;
string alter_name_new;
string alter_name_rename;
string space;
string result_2;
string alter_file;
string alter_file_new;
string filename_list;
string attributes_filename;
fstream attributes;
string config;
fstream read_config;
string p_name1;
string p_name2;
string p_value;
string gt1;
string lt1;
string ltc;
string gt2;
string attribute_line;
string parse;
string att;
string c_final;
int lt_count;
int gt_count;
stringstream selection;
string parameter_to_change;
string new_value;

//Selection
cin >> choice;

switch (choice)
{
	case 1:
		cout <<"You want to extract data."<<endl;
		break;

        case 2:
                cout <<"You want to update data."<<endl;
                break;
        case 3:
                cout <<"You want to delete data."<<endl;
                break;
        case 4:
                cout <<"You want to insert new data."<<endl;
                break;
        case 5:
                cout <<"You want to create a new database."<<endl;
		cout <<"What is the name of your new database?"<<endl;
		cout <<"Enter its name: ";


		//Creates directory for tables and indexes
		directory = "mkdir ./kendo/";
		cin >> name;
		cout << "Creating database directory for tables and indexes..." <<endl;
		result = directory + name;
		system(result.c_str());

		cout << "Now building configuration file..."<<endl;
		attributes_filename = "./kendo/" + name + "/" + name + ".config";
		attributes.open(attributes_filename.c_str(),ios::out);
		attributes << "<auto_close>OFF</auto_close>" << endl;
		attributes << "<auto_shrink>OFF</auto_shrink>" << endl;
		attributes << "<auto_create_statistics>OFF</auto_create_statistics>" << endl;
		attributes << "<auto_update_statistics>OFF</auto_update_statistics>" << endl;
		attributes << "<auto_update_statistics_async>OFF</auto_update_statistics_async>" << endl;
		attributes << "<change_tracking>OFF</change_tracking>" << endl;
		attributes << "<auto_cleanup>OFF</auto_cleanup>" << endl;
		attributes << "<change_retention>60</change_retention>" << endl;
		attributes << "<containment>OFF</containment>" << endl;
		attributes << "<cursor_close_on_commit>OFF</cursor_close_on_commit>" << endl;
		attributes << "<cursor_close_on_default>LOCAL</cursor_default>" << endl;
		attributes << "<date_correlation_optimization>OFF</date_correlation_optimization>" << endl;
		attributes << "<encryption>OFF</encryption>" << endl;
		attributes << "<db_state>ON</db_state>" << endl;
		attributes << "<db_update>READ_WRITE</db_update>" << endl;
		attributes << "<db_user_access>SINGLE_USER</db_user_access>" << endl;
		attributes << "<delayed_durability>DISABLED</delayed_durability>" << endl;
		attributes << "<db_chaining>OFF</db_chaining>" << endl;
		attributes << "<trustworthy>OFF</trustworthy>" << endl;
		attributes << "<default_fulltext_language>ENGLISH</default_fulltext_language>" << endl;
		attributes << "<default_language>ENGLISH</default_language>" << endl;
		attributes << "<nested_triggers>OFF</nested_triggers>" << endl;
		attributes << "<transform_noise_words>OFF</transform_noise_words>" << endl;
		attributes << "<two_digit_year_cutoff>9999</two_digit_year_cutoff>" << endl;
		attributes << "<non_transacted_access>FULL</non_transacted_access>" << endl;
		attributes << "<directory_name>./kendo/FILESTREAM</directory_name>" << endl;
		attributes << "<parameterization>FORCED</parameterization>" << endl;
		attributes << "<query_store>OFF</query_store>" << endl;
		attributes << "<operation_mode>READ_WRITE</operation_mode>" << endl;
		attributes << "<stale_query_threshold_days>2</stale_query_threshold_days>" << endl;
		attributes << "<data_flush_interval_seconds>60</data_flush_interval_seconds>" << endl;
		attributes << "<max_storage_size_MB>10</max_storage_size_MB>" << endl;
		attributes << "<interval_length_minutes>1440</interval_length_minutes>" << endl;
		attributes << "<sized_based_cleanup_mode>OFF</sized_based_cleanup_mode>" << endl;
		attributes << "<query_capture_mode>ALL</query_capture_mode>" << endl;
		attributes << "<max_plans_per_query>200</max_plans_per_query>" << endl;
		attributes << "<recovery>SIMPLE</recovery>" << endl;
		attributes << "<torn_page_detection>OFF</torn_page_detection>" << endl;
		attributes << "<page_verify>NONE</page_verify>" << endl;
		attributes << "<remote_data_archive>OFF</remote_data_archive>" << endl;
		attributes << "<target_recovery_time>60</target_recovery_time>" << endl;
		attributes << "<enable_broker>OFF</enable_broker>" << endl;
		attributes << "<disable_broker>localhost</disable_broker>" << endl;
		attributes << "<new_broker>localhost</new_broker>" << endl;
		attributes << "<error_broker_conversations>OFF</error_broker_conversations>" << endl;
		attributes << "<honor_broker_priority>OFF</honor_broker_priority>" << endl;
		attributes << "<allow_snapshot_isolation>OFF</allow_snapshot_isolation>" << endl;
		attributes << "<read_committed_snapshot>OFF</read_committed_snapshot>" << endl;
		attributes << "<memory_optimized_elevate_to_snapshot>OFF</memory_optimized_elevate_to_snapshot>" << endl;
		attributes << "<with_termination>NO_WAIT</with_termination>" << endl;
		attributes << "<ansi_null_default>ON</ansi_null_default>" << endl;
		attributes << "<ansi_nulls>ON</ansi_nulls>" << endl;
		attributes << "<ansi_padding>ON</ansi_padding>" << endl;
		attributes << "<ansi_warnings>ON</ansi_warnings>" << endl;
		attributes << "<concat_null_yields_null>ON</concat_null_yields_null>" << endl;
		attributes << "<quoted_identifier>ON</quoted_identifier>" << endl;
		attributes << "<arithabort>ON</arithabort>" << endl;
		attributes << "<numeric_roundabort>OFF</numberic_roundabort>" << endl;
		attributes << "<recursive_triggers>OFF</recursive_triggers>" << endl;
		attributes.close();
		cout<<"Your database was created successfully."<<endl;
                break;
        case 6:
                cout <<"You want to modify a database."<<endl;
		cout <<"Please select one of the following options: "<<endl;
		cout <<"1. Change the database name." <<endl;
		cout <<"2. Modify the database files."<<endl;
		cout <<"3. Configure the database attributes."<<endl;
		cout <<"4. Mirror a database."<<endl;
		cout <<"5. Configure a secondary db for replication"<<endl; 
		cout << "Your selection: ";

		cin >> alter;

		switch (alter)
		{
        		case 1:
                		cout <<"You want to change the database name. Which database would you like to change?"<<endl;
				
				system("ls ./kendo");
				cout <<"Enter the database name: ";
				cin >> alter_name;
				cout <<"What do you want to change the name to?"<<endl;
				cout <<"Enter the new database name here: ";
				cin >> alter_name_new;

				alter_name_rename = "mv ./kendo/";
				space = " ./kendo/";
				result_2 = alter_name_rename + alter_name + space + alter_name_new; 
				
				system(result_2.c_str());
				cout <<"Database name has been updated."<<endl;
                		break;
			case 2:
				cout <<"You want to modify the database files. Which database do you want to work in? "<<endl;
				system("ls ./kendo");
                                cout <<"Enter the database name: ";
                                cin >> alter_name;
				cout <<"Select the filename you would like to modify."<<endl;
				filename_list = "ls ./kendo/" + alter_name;
				cout <<"Enter the filename: ";
				system(filename_list.c_str()); 
				cin >> alter_file;
				cout <<"What do you want to rename the file to? "<<endl;
				cout <<"Enter the new filename: ";
				cin >> alter_file_new;

				alter_name_rename = "mv ./kendo/";
				space = " ./kendo/";
				result_2 = alter_name_rename + alter_name + "/" + alter_file + space + alter_name + "/" +  alter_file_new; 
				
				system(result_2.c_str());
                                cout <<"The database file has been updated."<<endl;
                                break;
			case 3:
				cout <<"You want to configure the database attributes. Select an database."<<endl;
				system("ls ./kendo");
                                cout <<"Enter the database name: ";
                                cin >> alter_name;
				filename_list = "./kendo/" + alter_name;
				config = filename_list + "/" + alter_name + ".config"; 
				read_config.open(config.c_str());

				//Set dummy characters
                                        lt1 = "<";
                                        gt1 = ">";
					gt2 = ">";
                                        ltc = "</";

				while(read_config.good())
				{
					getline(read_config,attribute_line);
					string str = attribute_line;
					
					//Parameter name
					unsigned first = str.find_first_of(lt1);
					unsigned first_end = first + 1;
					unsigned last = str.find_first_of(gt1);
					unsigned last_end = last;
					string strNew = str.substr(first_end,last_end-first_end);
					cout << "Parameter: " + strNew << endl;

					//Parameter value
					unsigned first_val = str.find_first_of(gt2);
                                        unsigned first_end_val = first_val + 1;
                                        unsigned last_val = str.find(ltc);
                                        unsigned last_end_val = last_val;
                                        string strNew_val = str.substr(first_end_val,last_end_val-first_end_val);
                                        cout << "Value: " + strNew_val << endl;
				}

				cout << "Enter the parameter you wish to make changes to. " << endl;
                                cout << "Paramter name: ";
                                cin >> parameter_to_change;
                               	cout << "The parameter to change is " + parameter_to_change + ". Enter the new value." << endl;
                                cout << "Enter the new value: ";
                                cin >> new_value;
				read_config.close();

				read_config.open(config.c_str());
				while(read_config.good())
				{
					getline(read_config,attribute_line);
					string str = attribute_line;

                                        //Parameter name
                                        unsigned first = str.find_first_of(lt1);
                                       	unsigned first_end = first + 1;
                                        unsigned last = str.find_first_of(gt1);
                                        unsigned last_end = last;
                                        string strNew = str.substr(first_end,last_end-first_end);
					if(strNew == parameter_to_change)
					{
						//Parameter value
                                        	unsigned first_val = str.find_first_of(gt2);
                                       		unsigned first_end_val = first_val + 1;
                                        	unsigned last_val = str.find(ltc);
                                        	unsigned last_end_val = last_val;
                                        	string strNew_val = str.substr(first_end_val,last_end_val-first_end_val);
						replace(attribute_line, strNew_val, new_value);
						cout << "The new parameter value of " + new_value + " has been updated successfully." << endl;
						read_config << attribute_line; 
					}
				}
				break;
		}
                break;
        case 7:
                cout <<"You want to create a new table."<<endl;
                break;
        case 8:
                cout <<"You want to modify a table."<<endl;
                break;
        case 9:
                cout <<"You want to delete a table."<<endl;
                break;
        case 10:
                cout <<"You want to create an index."<<endl;
                break;
        case 11:
                cout <<"You want to delete an index."<<endl;
                break;

}
}

