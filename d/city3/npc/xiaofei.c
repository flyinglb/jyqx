// xiaofei.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({ "xiao fei", "xiao" }));
        set("title","��ţ��ݽ�ϰ");
        set("long", "����ͷ����ݵ�������ϰ�������ĵ���Ҳ���ڽ�����ͷ���ˡ�\n");
        set("gender", "����");
        set("age", 35);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("finger", 80);
        set_skill("throwing", 80);
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
