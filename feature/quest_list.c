// quest_list.c
// make by Luky@hero

inherit ITEM;
inherit F_SAVE;

mapping last_updata;

void create()
{
        set_name("�����б��ļ�", ({ "quest list", "qs" }));
        if (clonep())
                set_default_object(__FILE__);
        setup();
}

string query_save_file()
{
	string id;
	if( !stringp(id = query("questlist_id")) ) return 0;
	//return DATA_DIR + "quest/" + id;
	return "/clone/quest/"+id;
}

void last_updata(string name)
{
        last_updata = ([ name: time() ]);
}

mapping query_last_updata() { return last_updata; }

mapping query_quest()
{
        mapping *quests;
        quests = query("notes");
        return quests[random(sizeof(quests))];
}

mapping *query_all_quest()
{
        mapping *quests;
        quests = query("notes");
        return quests;
}
