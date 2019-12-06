//from fy
//modified by wind

#define TOP_SIZE 15
#define BOT_SIZE 5
#define PK_SIZE 10
#define TOP_LST	"/log/top_lst"
#define BOT_LST "/log/bot_lst"
#define PK_LST  "/log/pk_lst"
mapping *read_text(string file);
mapping *read_text2(string file);
mapping *top_lst;
mapping *bot_lst;
mapping *pk_lst;

void create() 
{ 
//        string file;
	seteuid(getuid());
	top_lst = sort_array(read_text(TOP_LST),"sort_user",this_object());
	bot_lst = sort_array(read_text(BOT_LST),"sort_user2",this_object());
	pk_lst = sort_array(read_text2(PK_LST),"sort_user3",this_object());
}

void write_list()
{
	int i;
	string outp;
	rm(TOP_LST);
	rm(BOT_LST);
	rm(PK_LST);
	for(i=0;i<sizeof(top_lst);i++) {
		outp = sprintf("%s,%s,%d,%d,%d,%d\n",top_lst[i]["id"],top_lst[i]["name"],
		top_lst[i]["exp"],top_lst[i]["pot"],top_lst[i]["score"],
		top_lst[i]["sum"]);
		write_file(TOP_LST,outp,0);
	}
	for(i=0;i<sizeof(bot_lst);i++) {
		outp = sprintf("%s,%s,%d,%d,%d,%d\n",bot_lst[i]["id"],bot_lst[i]["name"],
                bot_lst[i]["exp"],bot_lst[i]["pot"],bot_lst[i]["score"],
                bot_lst[i]["sum"]);
		write_file(BOT_LST,outp,0);
	}
	for(i=0;i<sizeof(pk_lst);i++) {
		outp = sprintf("%s,%s,%d,%d,%d,%d,%d\n",pk_lst[i]["id"],pk_lst[i]["name"],
                pk_lst[i]["exp"],pk_lst[i]["pot"],pk_lst[i]["score"],
                pk_lst[i]["sum"],pk_lst[i]["pk"]);
		write_file(PK_LST,outp,0);
	}

}

mapping *read_text(string file)
{
//        string *line, *field;
        string *line;
	mapping *data;
	string lines,data_id;
	int i,j;
	j = 0;
	data = ({});
	lines= read_file(file);
	if(lines) {
 		line = explode(lines, "\n");
 		for(i=0;i<sizeof(line);i++) { 			
 			sscanf(line[i],"%s,%*s,%*d,%*d,%*d,%*d,%*d",data_id);
	                if( file_size(DATA_DIR + "login/" 
	                     + data_id[0..0] + "/" 
                             + data_id + __SAVE_EXTENSION__)<0 ) continue;
			data += ({ allocate_mapping(6) });
  			sscanf(line[i],"%s,%s,%d,%d,%d,%d",data[j]["id"],
			data[j]["name"],data[j]["exp"],data[j]["pot"],
			data[j]["score"],data[j]["sum"]);		
			j++;
 		}
	}
	return data;
}

mapping *read_text2(string file)
{
//        string *line, *field;
        string *line;
	mapping *data;
	string lines,data_id;
	int i,j;
	j = 0;
	data = ({});
	lines= read_file(file);
	if(lines) {
 		line = explode(lines, "\n");
 		for(i=0;i<sizeof(line);i++) {
 			sscanf(line[i],"%s,%*s,%*d,%*d,%*d,%*d,%*d",data_id);
	                if( file_size(DATA_DIR + "login/" 
	                     + data_id[0..0] + "/" 
                             + data_id + __SAVE_EXTENSION__)<0 ) continue;
			data += ({ allocate_mapping(7) });
  			sscanf(line[i],"%s,%s,%d,%d,%d,%d,%d",data[j]["id"],
			data[j]["name"],data[j]["exp"],data[j]["pot"],
			data[j]["score"],data[j]["sum"],data[j]["pk"]);
			j++;
 		}
	}
	return data;
}

int sort_user(mapping a, mapping b) { return b["sum"] - a["sum"]; }
int sort_user2(mapping a, mapping b) { return a["sum"] - b["sum"]; }
int sort_user3(mapping a, mapping b) { return b["pk"] - a["pk"]; }

void compare_status(object me)
{
	mapping mydata;
	int i;
	int T_ALREADY =0;
	int B_ALREADY =0;
	int P_ALREADY =0;
	if(wizardp(me)) return;
	if((int)me->query("mud_age") < 3600) return;
	mydata = ([]);
	mydata["id"]= (string) me->query("id");
	mydata["name"] = (string) me->query("name");
	mydata["exp"] = ((int)me->query("combat_exp")-1990) / ((int) me->query("mud_age")/3600 +1 );
	mydata["pot"] = ((int)me->query("potential")-290) /  ((int) me->query("mud_age")/3600 +1 );
	mydata["score"] = (int)me->query("score")  /  ((int) me->query("mud_age")/3600 +1 );
	mydata["sum"] = mydata["exp"] + mydata["pot"]*10 + mydata["score"] * 100 /3;
	mydata["pk"]= (int) me->query("PKS");
	// / ((int) me->query("mud_age")/86400 +1 );
	
	// compare with the top list
	for(i=0;i<sizeof(top_lst);i++)
	if(top_lst[i]["id"] == mydata["id"]) {
		top_lst -= ({ top_lst[i] });
		top_lst += ({ mydata });
		T_ALREADY =1;
		break;
	}
	if(!T_ALREADY) top_lst += ({ mydata });

	// compare with the bottom list
	for(i=0;i<sizeof(bot_lst);i++)
		if(bot_lst[i]["id"] == mydata["id"]) {
        		bot_lst -= ({ bot_lst[i] });
        		bot_lst += ({ mydata });
        		B_ALREADY =1;
        		break;
		}
	if(!B_ALREADY) bot_lst += ({ mydata });

	// compare with the pk list
	for(i=0;i<sizeof(pk_lst);i++)
		if(pk_lst[i]["id"] == mydata["id"]) {
        		pk_lst -= ({ pk_lst[i] });
        		pk_lst += ({ mydata });
        		P_ALREADY =1;
        		break;
		}
	if(!P_ALREADY) pk_lst += ({ mydata });

	top_lst = sort_array(top_lst,"sort_user",this_object());
	bot_lst = sort_array(bot_lst,"sort_user2",this_object());
	pk_lst =  sort_array(pk_lst,"sort_user3",this_object());
	
	// check the list size, get rid of extras from the bottom of the list
	while(sizeof(top_lst) > TOP_SIZE)
		top_lst -= ({ top_lst[sizeof(top_lst)-1] });
		while(sizeof(bot_lst) > BOT_SIZE)
        		bot_lst -= ({ bot_lst[sizeof(bot_lst)-1] });
				while(sizeof(pk_lst) > PK_SIZE)
        				pk_lst -= ({ pk_lst[sizeof(pk_lst)-1] });

}

string show_top()
{
	int i;
	string msg;
	msg = "玩程报告前"+chinese_number(TOP_SIZE)+"名：\n";
	msg += sprintf("%-10s%-10s%-15s%-15s%-15s%-15s\n",
	"英文名","中文名","经验／小时","潜能／小时","评价／小时","综合／小时");
	for(i=0;i<sizeof(top_lst);i++)
	msg += sprintf("%-10s%-10s%-15d%-15d%-15d%-15d\n",
	top_lst[i]["id"],top_lst[i]["name"],top_lst[i]["exp"],top_lst[i]["pot"],
	top_lst[i]["score"],top_lst[i]["sum"]);
	return msg;
}

string show_bot()
{
	int i;
	string msg;
	msg = "玩程报告后"+chinese_number(BOT_SIZE)+"名：\n";
	msg += sprintf("%-10s%-10s%-15s%-15s%-15s%-15s\n",
	"英文名","中文名","经验／小时","潜能／小时","评价／小时","综合／小时");
	for(i=0;i<sizeof(bot_lst);i++)
		msg += sprintf("%-10s%-10s%-15d%-15d%-15d%-15d\n",
		bot_lst[i]["id"],bot_lst[i]["name"],bot_lst[i]["exp"],bot_lst[i]["pot"],
		bot_lst[i]["score"],bot_lst[i]["sum"]);
	return msg;
}

string show_pk()
{
	int i;
	string msg;
	msg = "杀手报告前"+chinese_number(PK_SIZE)+"名：\n";
	msg += sprintf("%-10s%-10s%-15s%-15s%-15s%-15s%-15s\n",
	"英文名","中文名","经验／小时","潜能／小时","评价／小时","综合／小时","杀人");
	for(i=0;i<sizeof(pk_lst);i++)
		msg += sprintf("%-10s%-10s%-15d%-15d%-15d%-15d%-15d\n",
		pk_lst[i]["id"],pk_lst[i]["name"],pk_lst[i]["exp"],pk_lst[i]["pot"],
		pk_lst[i]["score"],pk_lst[i]["sum"],pk_lst[i]["pk"]);
return msg;
}

