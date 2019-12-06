mapping *quests;
mapping *read_table(string file);
string *roomlines;
varargs void init_dynamic_quest(int hard);
varargs int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
string dyn_quest_list();
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
void create()
{
	string file;
	quests = read_table("/quest/questlist.c");
	file = read_file("/quest/dynamic_location");
	roomlines = explode(file,"\n");	
	CRON_D->set_last_hard_dis();
	init_dynamic_quest(1);
}
int quest_reward(object me, object who,object quest_item)
{
	mapping quest;
	int exp,pot,score;

	quest = quest_item->query("dynamic_quest");
	if(base_name(who) != quest_item->query("dynamic_quest")) 
		return 0;
        exp =200+random(500);
        pot = exp/7;
        score = random(10)+1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
        message("shout", HIG "【任务传言】：" + HIG + "听说" + me->query("name") + "成功的把" +
        who->query("name") + "的"+quest_item->name()+HIG+"拿了回来\n"+me->query("name")+"被奖励了：" + HIR +
        chinese_number(exp) + HIG"点实战经验"+ HIR + chinese_number(pot) + HIG"点潜能" + HIR + chinese_number(score)+ HIG "点综合评价\n"NOR,users());
	me->add("TASK",1);
	destruct(quest_item);
	return 1;
}

varargs void init_dynamic_quest(int hard)
{
	int i;
	for( i=0; i < sizeof(quests); i++)
		spread_quest(quests[i],hard);
}
varargs int spread_quest(mapping quest, int hard)
{
	object obj0;
	object cur_obj;
	object tar;
	object *inv;
	object *target=({});
	int i;
	string location;

	if(already_spreaded(quest["file_name"],hard)) return 0;
	reset_eval_cost();
	location = roomlines[random(sizeof(roomlines))];
	obj0=find_object(location);
	if(obj0)
		obj0->reset();
	else
		obj0=load_object(location);
	cur_obj =obj0;
	if(cur_obj) {
		inv = all_inventory(cur_obj);
		for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->is_character() && !userp(inv[i]))
			target += ({ inv[i] });
		if(inv[i]->is_container()) 
			target += ({ inv[i] });
		}
	}
	if(sizeof(target)) 
		cur_obj = target[random(sizeof(target))];
	if(cur_obj) {
		tar = new(quest["file_name"]);
		tar->set("value",0);
		tar->set("dynamic_quest",quest);
		tar->move(cur_obj);		
	}
	return 1;
}

string dyn_quest_list()
{
	string output="";
	object owner,item;
        int i;

        for( i=0; i < sizeof(quests); i++) {
		reset_eval_cost();
		if(!objectp(owner= find_object(quests[i]["owner_name"])))
			owner = load_object(quests[i]["owner_name"]);
        	if(!objectp(item= find_object(quests[i]["file_name"])))
        		item = load_object(quests[i]["file_name"]);
		if(already_spreaded(quests[i]["file_name"])) {
			if(random(2))
				output += sprintf(HBBLU+HIC"%8s"NOR" 的『%s』（%s）\n",owner->query("name"),item->query("name"),item->query("id"));
		}
		else {
			output += sprintf(HBBLU+HIC"%8s"NOR" 的一%s『%s』（%s）\n",owner->query("name"),item->query("unit"),item->query("name"),item->query("id"));
		}
	}
	output += sprintf("\t\t\t\t\t目前一共有"HIR"%s"NOR"件任务。\n"NOR,chinese_number(i));
	return output;
}

varargs int already_spreaded(string str,int hard)
{
        object ob,*ob_list;
        int i;

        if(!str) 
		return 0;
	if(hard) {
	        ob_list = children(str);
        	for(i=0; i<sizeof(ob_list); i++) {
                	ob=find_env(ob_list[i]);
			if(ob) { 
				ob_list[i]->move(VOID_OB);
				destruct(ob_list[i]);
			}
		}
		return 0;
	}
	else {
		if(!str) 
			return 0;
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
                	ob=find_env(ob_list[i]);
                	if(ob)
				return 1;
		}
		return 0;
	}
}

object find_env(object ob)
{
        while(ob) {
	        if(ob->query("coor") ) 
			return ob;
        	else 
			ob=environment(ob);
        }
        return ob;
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");

	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' )
			continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) 
			continue;
		if( !fn ) 
			data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) 
			++rn;
	}
	return data;
}

void big_reward(object me, object who, object item)
{
	tell_object(me,"你真行！！\n");
}

void execute_accept_object(object me, object who, object item)
{
	who->accept_object(me,item);
}
