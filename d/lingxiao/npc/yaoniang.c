//LUCAS 2000-6-18
// yaoniang.c
inherit NPC;

void create()
{
        set_name("���", ({ "yao niang", "yao" }) );
        set("gender", "Ů��" ); 
        set("title", "���������");        set("age", 17);
        set("per", 30);
        set("str", 16);
        set("age", 30);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");
        set("inquiry", ([
            "������"   : "��ү�Ӳ�֪Ϊʲô,���Լ��ص�������,˵˼ʲô����",
            "����"   : "û��үͬ��,���ǽ���ȥ�ġ�",
        ]) );

        set("max_qi",800);
        set("max_jing",500);
       set("combat_exp", 10000);

        set("long",     "����ǰ����ڵ����,�ܵð����ڳ��š�\n");


        setup();

        carry_object("/clone/cloth/cloth")->wear();

}



