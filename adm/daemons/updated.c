// updated.c
// modified by wind

void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int i, level; 
	mapping my, skill_status,map;
	string *sname;
	float exper;
	string name,id,or,type,time;
	int value,lv;

	my = ob->query_entire_dbase();

	if( (ob->query("weapon/制造")==1) )
	{
		name = ob->query("weapon/名称");
		id = ob->query("weapon/代号");
		or = ob->query("weapon/原料");
		type=ob->query("weapon/类型");
		time=ob->query("weapon/时间");
		value=ob->query("weapon/值");
		lv = ob->query("weapon/等级");
		ob->delete("weapon");
		ob->set("weapon/make",1);
		ob->set("weapon/name",name);
		ob->set("weapon/id",id);
		ob->set("weapon/or",or);
		ob->set("weapon/type",type);
		ob->set("weapon/value",value);
		ob->set("weapon/lv",lv);
		ob->set("weapon/time",time);
	}

			
        if (wizardp(ob)) return;

	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) ) my["eff_qi"] = my["max_qi"];
	if( my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
	if( my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
	if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
	if( my["qi"] > my["eff_qi"] ) my["qi"] = my["eff_qi"];

	exper = to_float(ob->query("combat_exp"));

	if ( !(skill_status = ob->query_skills()) ) return;
	sname  = keys(skill_status);
       	map = ob->query_skill_map();

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			ob->set_skill(sname[i], level);
		}
/*         if(!ob->query_skill_map()) continue;
         if(undefinedp(map[sname[i]])) continue;
         if(ob->query_skill(sname[i],1)<50) continue;
         if(ob->query_skill(sname[i],1)*3<ob->query_skill(map[sname[i]],1)*2) 
        {
         ob->set_skill(map[sname[i]],ob->query_skill(sname[i],1)*3/2);
         tell_object(ob,"对不起！你的"+map[sname[i]]+"已经被调整,请提高你的"+sname[i]+"！\n");
        }
*/
	}
        ob->enable_player();
}
