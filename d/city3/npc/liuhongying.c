// liuhongying.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("������", ({ "liu hongying", "liu" }));
        set("title","��ţ��ݽ�ϰ");
        set("long", "����ͷ����ݵ�������ϰ����ɱ�С����Ŷ��\n");
        set("gender", "Ů��");
        set("age", 32);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("sword", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/jinniu_paied")==1) return 0;
        return 1;
}
