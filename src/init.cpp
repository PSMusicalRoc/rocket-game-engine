#include "init.hpp"

void kiwi_end_dialogue()
{
    SharedPtrEntity kiwi = find_entities_by_label("kiwi")[0];
    int index = find_entity_position(kiwi);
    GLOBAL_ENTITY_LIST.erase(GLOBAL_ENTITY_LIST.begin() + index);
}

void kiwi_continue_dialogue()
{
    SharedPtrEntity kiwi = find_entities_by_label("kiwi")[0];
    
    auto kiwi_text = std::any_cast<AnimatedTextRenderer>(&kiwi->component_list.at(1));

    kiwi_text->advance_dialogue();
}

void init()
{
    /*
    * FPS Entity
    */

    auto fps_ent = create_entity(0, 0);
    fps_ent->labels.emplace_back("ui");
    fps_ent->labels.emplace_back("fps");
    add_component_to_entity<TextRenderer>(TextRenderer(std::string("300"), Fonts::ARIAL), fps_ent);
    Logger::log(LogLevel::INFO, "Added component to FPS Entity!");
    TextRenderer* txt = std::any_cast<TextRenderer>(&fps_ent->component_list.at(0));
    txt->size_and_pos.h = 100;
    txt->size_and_pos.w = 1000;







    /*
    * Kiwi
    */
   
    auto kiwi = create_entity(0, 0);
    kiwi->labels.emplace_back("kiwi");
    //auto shared = std::make_shared<Animation>(Animation(Spritesheet("res/img/kiwi/Kiwi_Megaman_Battle_Network.png")));
    add_component_to_entity<SpriteRenderer>(SpriteRenderer("idle", Animation(Spritesheet("res/img/kiwi/Kiwi_Megaman_Battle_Network.png"))), kiwi);
    SpriteRenderer* kiwi_sprite = std::any_cast<SpriteRenderer>(&kiwi->component_list.at(0));
    kiwi_sprite->do_clip = true;

    kiwi_sprite->pos = {100, 700, 200, 200};
    kiwi_sprite->switch_animation("idle");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                add_frame_to_animation(kiwi_sprite->animations.at("idle").get(), {480 * j, 480 * i, 480, 480});
            }
        }
    }

    add_animation_to_spriterenderer(kiwi_sprite, "whale_mom", Animation(Spritesheet("res/img/whale_mom/Whale_Mom_Megaman_Battle_Network_New.png")));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                add_frame_to_animation(kiwi_sprite->animations.at("whale_mom").get(), {480 * j, 480 * i, 480, 480});
            }
        }
    }


    add_component_to_entity<AnimatedTextRenderer>(AnimatedTextRenderer(100), kiwi);
    
    AnimatedTextRenderer* kiwi_text = std::any_cast<AnimatedTextRenderer>(&kiwi->component_list.at(1));

    kiwi_text->messages.emplace_back(Message("Hi there, this is a test of the animated scrolling text!\n"
                                    "Hopefully, it's also multiline as well!\n"
                                    "Thank you Asher for making the poggers art! :PogU:"));
    kiwi_text->messages.at(0).font = Fonts::SMALL_ARIAL;
    
    kiwi_text->messages.emplace_back(Message("Test2"));
    kiwi_text->messages.at(1).font = Fonts::SMALL_ARIAL;
    kiwi_text->messages.at(1).message_done_callback = [](){
        
        auto kiwi = find_entities_by_label("kiwi")[0];
        auto kiwi_sprite = std::any_cast<SpriteRenderer>(&kiwi->component_list.at(0));
        kiwi_sprite->switch_animation("whale_mom");
        };

    kiwi_text->messages.emplace_back(Message("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB"));
    kiwi_text->messages.at(2).font = Fonts::SMALL_ARIAL;


    kiwi_text->size_and_pos.x = 305;
    kiwi_text->size_and_pos.y = 700;
    kiwi_text->end_of_dialogue_callback = kiwi_end_dialogue;


    add_component_to_entity<ControlsComponent>(ControlsComponent(), kiwi);
    ControlsComponent* kiwi_controls = std::any_cast<ControlsComponent>(&kiwi->component_list.at(2));

    set_control_callback(kiwi_controls, SDL_SCANCODE_A, kiwi_continue_dialogue);
}