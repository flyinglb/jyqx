// boshou.c ����

inherit NPC;

void create()
{
        set_name("����������", ({ "boshou"}));
        set("long", 
                "���������ɵĴ����֡�\n"
                "����������һ��ͭ�࣬һ����һ�߳���ɤ�ӳ�Щ����Ļ���\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 2000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);

//      create_family("������", 3, "������");

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
"��������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ�������御����\n",
"��������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
"��������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
        }) );

        carry_object("/d/xingxiu/obj/tongbo")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

