// gaoshou.c
#include <ansi.h>
#include <login.h>
inherit ITEM;
//inherit F_AUTOLOAD;
inherit F_AUTOLOAD;
void create()
{
        set_name(HIR"�������а�"NOR, ({ "stone" }) );
        set("long","���а�\n");
        set("unit", "��");
        set("value",4000);
}

//int query_autoload() { return 1; }//autoload����
int query_autoload() { return 1; }//autoload����

void init()
{
        add_action("do_cha", "chabang");
}
int do_cha(string arg)
{
        string* gaoshoulist;
//for(int i=0; i<sizeof(gaoshoulist); i++)
        for(int i=0; i<sizeof(gaoshoulist); i++)

                printf(gaoshoulist);
                printf(gaoshoulist, '\n');

        write("\n");
        return 1;
}
