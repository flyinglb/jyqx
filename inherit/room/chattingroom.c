//Create by Eatdami@MX (10/14/2000)

inherit ROOM;
string *discard_cmds =({"sleep","respitate","jingzuo","array","duanlian","ansuan",
			"touxi","persuade","teach","exert","exercise","study",
			"learn","kill","steal","conjure","fight","hit","perform",
                        "practice","research","lian","tuna","yun","du","dazuo",
                        "give","put","get","drop","eat","chi","drink","he","location"});

void setup()
{
        set("no_fight",1);
        set("no_magic",1);
        set("no_sleep_room",1);
	::setup();
}

int is_chatting_room()
{
	return 1;
}

void init()
{
    if (wizardp(this_player()))
	return;
    add_action("discard",discard_cmds);
}

int discard()
{
        tell_object(this_player(),"这儿的规矩是：君子动口不动手。\n");
        return 1;
}

/*
void reset()
{
        object *inv;
        int i, i1;
        
        inv = all_inventory();
        for(i=0,i1=sizeof(inv);i<i1;i++) {
//                if( userp(inv[i]) || living(inv[i]) ) continue;
                if( userp(inv[i]) ) continue;
                inv[i]->move(VOID_OB);
                destruct(inv[i]);
        }
        return ::reset();
}
*/
