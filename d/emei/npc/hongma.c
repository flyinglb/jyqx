// hongma.c ����

#include <command.h>
#include <dbase.h>
#include <origin.h>

inherit NPC;

void create()
{
        set_name("����", ({ "hong ma" }));
        set("long","һƥ����ȫ���죬��һ����ë��\n");
        set("race", "Ұ��");
        set("age", 5);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 30);
        set("int", 18);
        set("shen", 1);
        set("combat_exp", 1000);
        setup();
}
