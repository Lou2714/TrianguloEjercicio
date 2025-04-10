pipeline {
    agent {
        label 'linux'
    }
    environment { 
        REPO_PRUEBAS = 'https://github.com/Lou2714/PruebasCatch2.git'
        REPO_ESTUDIANTE = 'https://github.com/Lou2714/TrianguloEjercicio.git'
        REPO_PRUEBAS_CREDENTIALS = credentials('ProbandoJenkins')
    }
    stages{ /*
        stage('Checking SCM'){
            steps{
                checkout scm
            }
        }*/
        stage('Getting test repository'){
            steps{
                dir('repos'){
                    checkout scm
                    git(
                        url: "${REPO_PRUEBAS}",
                        credentialsId: 'ProbandoJenkins',
                        branch: 'main'
                    )
                }/*
                git(
                    url: "${REPO_ESTUDIANTE}",
                    credentialsId: 'ProbandoJenkins',
                    branch: 'main'
                )*/
            }
        }
        stage('Checking directoryx2'){
            steps{
                script{
                    def repoURL = sh(script: "echo ${REPO_PRUEBAS}", returnStdout: true).trim()
                    def reponame = repoURL.split('/').last().replace('.git', '')
                    echo "${reponame}"
                }
            }
        }
        stage('Debug') {
            steps {
                sh 'cd repos && ls -la'

                sh 'pwd && ls -la'
            }
        }
    }
    post { 
        always { 
            cleanWs()
            echo 'I will always say Hello again!'
        }
    }
}