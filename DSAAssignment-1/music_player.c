#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t *create_playlist() // return a newly created doubly linked list
{
    // DO NOT MODIFY!!!
    playlist_t *playlist = (playlist_t *)malloc(sizeof(playlist_t));
    playlist->list = create_list();
    playlist->num_songs = 0;
    playlist->last_song = NULL;
    return playlist;
}

void delete_playlist(playlist_t *playlist) // delete the playlist
{
    // DO NOT MODIFY!!!
    delete_list(playlist->list);
    free(playlist);
}

music_queue_t *create_music_queue() // return a newly created queue
{
    // DO NOT MODIFY!!!
    return create_queue();
}

void clear_music_queue(music_queue_t *q) // clear the queue q
{
    // DO NOT MODIFY!!!
    delete_queue(q);
}

void add_song(playlist_t *playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
    if (where == -1)
        insert_front(playlist->list, song_id);
    else if (where == -2)
        insert_back(playlist->list, song_id);
    else if (where > 0)
        insert_after(playlist->list, song_id, where);
    playlist->num_songs++;
}

void delete_song(playlist_t *playlist, int song_id) // TODO: remove song id from the playlist
{
    delete_node(playlist->list, song_id);
    playlist->num_songs--;
}

song_t *search_song(playlist_t *playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
    return search(playlist->list, song_id);
}

void search_and_play(playlist_t *playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
    song_t *res = search_song(playlist, song_id);
    if (res == NULL)
        return;
    play_song(res->data);
    playlist->last_song = res;
}

void play_next(playlist_t *playlist, music_queue_t *q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
    if (playlist->list->head == NULL)
        return;
    if (empty(q))
    {
        if (playlist->last_song && playlist->last_song->next)
        {
            search_and_play(playlist, playlist->last_song->next->data);
        }
        else
        {
            search_and_play(playlist, playlist->list->head->data);
        }
    }
    else
    {
        play_from_queue(q);
    }
}

void play_previous(playlist_t *playlist) // TODO: play the previous song from the linked list
{
    if (is_empty(playlist->list))
        return;
    else
    {
        if (playlist->last_song && playlist->last_song->prev)
        {
            search_and_play(playlist, playlist->last_song->prev->data);
        }
        else
        {
            search_and_play(playlist, playlist->list->tail->data);
        }
    }
}

void play_from_queue(music_queue_t *q) // TODO: play a song from the queue
{
    if (!empty(q))
        play_song(dequeue(q));
    return;
}

void insert_to_queue(music_queue_t *q, int song_id) // TODO: insert a song id to the queue
{
    enqueue(q, song_id);
}

void reverse(playlist_t *playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
    song_t *temp = NULL;
    song_t *current = playlist->list->head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        playlist->list->head = temp->prev;
}

void k_swap(playlist_t *playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
    int i = 0;
    song_t *jth = playlist->list->head;

    song_t *temp = NULL;

    song_t *iter = playlist->list->head;
    int j = i + k;
    while (j <= playlist->num_songs)
    {
        temp->data = iter->data;
        while (j--)
        {
            jth = jth->next;
        }
        temp = iter->next;
        iter->next = jth->next;
        jth->next = temp;

        if (iter->next != NULL)
            iter->next->prev = iter;
        if (jth->next != NULL)
            jth->next->prev = jth;

        temp = iter->prev;
        iter->prev = jth->prev;
        jth->prev = temp;

        if (iter->prev != NULL)
            iter->prev->next = iter;
        if (jth->prev != NULL)
            jth->prev->next = jth;

        iter = jth->next;
        jth = iter;
        // j = i + k;
        i++;
    }
}

void shuffle(playlist_t *playlist, int k) // TODO: perform k_swap and reverse
{
    k_swap(playlist, k);
    reverse(playlist);
}

song_t *debug(playlist_t *playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
    song_t *slow = playlist->list->head;
    song_t *fast = slow;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return NULL;
    slow = playlist->list->head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void display_playlist(playlist_t *p) // Displays the playlist
{
    // DO NOT MODIFY!!!
    display_list(p->list);
}

void play_song(int song_id)
{
    // DO NOT MODIFY!!!
    printf("Playing: %d\n", song_id);
}
