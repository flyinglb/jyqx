// chenhu.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���", ({ "chen hu", "chen" }));
        set("title","��ţ��ݽ�ϰ");
        set("long", "����ү�������Ҳæ�˼�ʮ���ˣ���������Я������\n");
        set("gender", "����");
        set("age", 65);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("cuff", 80);
        set_skill("staff", 80);
        set_skill("club", 80);
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
