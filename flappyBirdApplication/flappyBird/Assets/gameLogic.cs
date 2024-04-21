using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class gameLogic : MonoBehaviour
{
    public Text scoreLabel;
    public pipeLogic pipeLogic;
    private int playerScore;
    public pipeSpawnerLogic pipeSpawnerLogic;
    public birdLogic birdLogic;
    public GameObject gameOverScreen;

    [ContextMenu("Increment score")]
    public void incrementScore(int scoreOffset)
    {
        if (birdLogic.isAlive())
        {
            playerScore += scoreOffset;
            scoreLabel.text = playerScore.ToString();
            if (playerScore % 3 == 0)
            {
                pipeLogic.updateSpawnRate(2);
                birdLogic.increaseDifficulty();
            }
        }
    }

    public void restartGame()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    public void gameOver()
    {
        gameOverScreen.SetActive(true);
    }

    void Start()
    {
        pipeLogic = GameObject.FindGameObjectWithTag("Pipe").GetComponent<pipeLogic>();
        pipeSpawnerLogic = GameObject.FindGameObjectWithTag("Spawner").GetComponent<pipeSpawnerLogic>();
        birdLogic = GameObject.FindGameObjectWithTag("bird").GetComponent <birdLogic>();
    }

    void Update()
    {
        
    }
}
