// mengmianr.c
// shilling 97.2

inherit NPC;

void create()
{
        set_name("������", ({ "mengmian ren", "ren" }));
        set("long", 
                "һ�������沿������ɫҹ���·��������ˡ�\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 0);
        set("combat_exp", 10000);

        set_skill("force", 30);
        set_skill("dodge", 25);
        set_skill("parry", 20);
        set_skill("blade", 30);
        set_skill("lingboweibu", 25);
        set_skill("beiming-shengong", 30);
        set_skill("ruyi-dao", 30);

        map_skill("blade", "ruyi-dao");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");

        create_family("��ң��", 5, "����");
        setup();
        
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}

