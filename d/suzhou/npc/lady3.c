// lady3.c
inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "ya huan","ya","huan" }) );
        set("gender", "Ů��" );
        set("age", 16);
        set("long", "����һ����ò�����������а��Ѿ�������ڴ��ֵĿ��ġ�\n");
        set("shen_type", 1);
        set("combat_exp", 1000);
        set("str", 20);
        set("dex", 18);
        set("con", 19);
        set("int", 20);
        set("attitude", "friendly");
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("score", 800);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 8);
        set_temp("apply/defense", 12);
        set_temp("apply/damage", 11);
        set_temp("apply/armor", 7);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
             say("Ѿ��Ц��˵������λ" + RANK_D->query_respect(ob)
             + "����ӭ����ʨ���֡�\n");
        return;
}
